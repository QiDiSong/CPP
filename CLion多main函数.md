记得大一学C语言的时候，我们就知道一个工程中只能有一个main函数

最近下载了CLion，我很懒，想在一个工程下建好几个c文件，里面都有main函数，结果编译运行的时候不通过

这才想起来，无论有多少复杂的c文件和函数，绝对有且只有一个main函数

记得把其他带有main函数的文件都删掉之后，将CMakeLists.txt 中对应的文件名也删掉

------

后来看了其他大佬的文章，发现是可以在一个工程下编写多个main函数的C文件的

![在这里插入图片描述](https://img-blog.csdnimg.cn/20181222145132476.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2p1c3Rpbnp3ZA==,size_16,color_FFFFFF,t_70)

比如我这里有两个C文件，nihao.c和 DLinkList.c

里面都有main函数

我可以打开CMakeLists.txt文件修改执行文件

![在这里插入图片描述](https://img-blog.csdnimg.cn/20181222145245366.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2p1c3Rpbnp3ZA==,size_16,color_FFFFFF,t_70)

我给每个文件起了别名 main1 main2，必须要起别名，我也不知道为啥，我去掉之后就不行了

然后编译运行的时候在右上角选择对应的main函数
![在这里插入图片描述](https://img-blog.csdnimg.cn/20181222145533426.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2p1c3Rpbnp3ZA==,size_16,color_FFFFFF,t_70)

最后点右边的三角形就可以运行了
