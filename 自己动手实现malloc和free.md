# 1. Malloc介绍

malloc()是C语言中动态存储管理的一组标准库函数之一，其作用就是从内存的动态存储区(堆)中分配一个长度为size的连续内存空间。参数为一个无符号的整数，返回值则是指向所分配的连续存储空间起始地址的指针。如果内存不足，则函数分配内存失败会返回NULL。

在Linux中，每个进程可访问的虚拟内存空间为3G，但在程序编译时，不可能也没必要为程序分配这么大的空间，只分配并不大的数据段空间，程序中动态分配的空间就是从这一块分配的。如果这块空间不够，malloc函数族（realloc，calloc等）就调用sbrk函数将数据段的尾部移动，sbrk函数在内核的管理下将虚拟地址空间映射到内存，供malloc函数使用。注意，sbrk不是系统调用，是C库函数。系统调用通常提供一种最小功能，而库函数通常提供比较复杂的功能。有关sbrk详细内容可参见这篇文章：sbrk详解 。如果待分配的内存很大，则有可能直接调用mmap来映射内存。这里顺便提一下malloc和calloc的区别，malloc对它所分配的内存是不会清零的，而calloc则会对它所分配的内存清零。

    #include <unistd.h> // 使用brk/sbrk，需要使用这个头文件


# 2. 动手实现Malloc

首先定义一个控制内存分配的结构体内存控制块mcb如下：

    typedef struct mcb {
   		int available;
    	int size;
    } mcb;

其中available表示该内存块是否可用，1表示可用，0表示不可用。size表示该内存块的大小。 **我们在malloc一段内存的时候，会在基本大小的基础上加上结构体mcb的大小，而返回的分配内存地址则需要跳过结构体mcb。**

定义几个全局变量如下，memStart表示内存分配时查找空闲内存的起始地址。lastAddr则表示最后一个有效的内存地址，hasInit代表是否已经初始化。初始化函数设置memStart为当前堆结尾位置，而lastAddr也设置为当前堆结尾位置。

    void *memStart;
    void *lastAddr;
    int hasInit;

    void init()
    {
	    lastAddr = sbrk(0); //初始化有效内存的最尾端地址为堆尾位置
	    memStart = lastAddr; //初始化查找空闲内存的起始地址
	    hasInit = 1;
    }

**malloc函数实现如下：**
    
    void* malloc_mem(int num)
    {
    	if (!hasInit)
    		init();
    	void *current = memStart; //设置查询空闲内存的起始地址
    	void *ret = NULL; //ret为返回最终分配内存的地址
     
    	num += sizeof(mcb); //将基础大小加上内存控制块结构体mcb的大小
    	//遍历已经分配的内存块看是否有合适大小的空闲的内存块可用，
    	//如果有空闲内存块且它的大小大于要分配的大小，则设置占用状态标记,
    	//设置返回的内存地址ret为当前遍历到的空闲内存块起始地址，并跳出循环。
    	while (current != lastAddr) { 
    		mcb *pcurrent = current; 
    		if (pcurrent->available && pcurrent->size >= num){
    			pcurrent->available = 0; 
    			ret = current; 
    			break; 
    		} 
    		current += pcurrent->size; //没找到合适大小的空闲块，则遍历下一个内存块 
    	}
    	if (!ret) { //如果没有找到空闲块，或者是第一次分配 
    		sbrk(num); //调整堆尾部大小，增加num 
    		ret = lastAddr; //设置ret为之前的有效地址 
    		lastAddr += num; //更新最后一个有效地址，加上新分配的内存块大小
    		mcb *pcb = ret; 
    		pcb->size = num; 
    		pcb->available = 0; 
    	} 
    	ret += sizeof(mcb); // 返回ret，注意这里跳过了内存控制块的大小 
    	return ret;
    }

# 3. 实现Free函数 #

既然写了malloc，则free就很好写了， **因为传入参数为内存块真正的起始地址(跳过了mcb结构体大小)，所以这里需要先减去结构体mcb的大小才能得到内存控制块mcb的内存位置** ，而后清除占用标记即可。

    void free_mem(void *start)  
    {  
	    mcb *pmcb = (mcb *)(start - sizeof(mcb));  
	    pmcb->available = 1;  
    } 
