### 函数

- **函数模板**：
  只适用于函数体相同、函数的参数个数相同而类型不同的情况，如果参数的个数不同，则不能用函数模板
- **函数重载**：
  参数的个数和类型可以都不相同。但不能只有函数的类型不同而参数的个数和类型相同。
- **默认参数**：
  实参与形参的结合是从左至右顺序进行的。因此指定默认值的参数必须放在形参表列中的最右端，否则出错。
- **函数的声明和定义**：
  函数的声明是函数的原型，而函数的定义是函数功能的确立；
- **变量的声明和定义**：
  把建立存储空间的声明称为定义，把不需要建立存储空间的声明称为声明；

### 指针和数组

- **多维数组名作函数参数**：
  必须指定第二维（即列）的大小，且应与实参的第二维的大小相同
- **变量与指针**：
  变量的指针就是变量的地址。用来存放变量地址的变量就是指针变量。
- **指针变量**：
  一般的C++编译系统都为指针变量分配4个字节的存储单元。但在定义指针变量时必须指定基类型。
- **函数调用**：
  实参变量和形参变量之间的数据传递是单向的“值传递”方式，调用函数时不会改变实参指针变量的值，但可以改变实参指针变量所指向变量的值。
- ***(p++)、\*(++p)**:
  前者先取*p的值，然后使p加1。后者是先使p加1，再取*p
- **函数指针**：
  一个函数在编译时被分配一个入口地址，这个函数入口地址就成为函数的指针。
- **指针函数**：
  返回指针值的函数，eg. 类型名 *函数名(参数列表)

```
指针数组    类型名 *数组名[数组长度]
数组指针    类型名 (*指针名)[数组长度]12
```

- **引用**：
  引用不是一种独立的数据类型，必须指定其代表某一类型的实体(如变量、类对象)，不能定义引用数组，不能定义指向引用的指针。引用变量主要用作函数参数，它可以提高效率，而且保持程序良好的可读性。

### 结构体和对象

- **动态分配撤销内存**：
  new和 delete是运算符，不是函数
- **类类型访问限制**：
  如果在类的定义中既不指定private，也不指定public，则系统就默认为是私有的。
- **结构体vs类**：
  用struct声明的类，如果对其成员不作private或public的声明，系统将其默认为public，而用class声明的类，如果不作private或public的声明，系统将其成员默认为private。
- **成员函数**：
  不论成员函数在类内定义还是在类外定义，成员函数的代码段都用同一种方式存储，即都不占用对象的存储空间。
- **信息隐蔽**：
  类的公用接口与私有实现的分离。当接口与实现（对数据的操作）分离时，只要类的接口没有改变，对私有实现的修改就不会影响程序的其他部分。
- **默认构造函**数：
  调用构造函数时不必给出实参的构造函数。一个类只能有一个默认构造函数。由于不需要实参也可以调用构造函数，因此全部参数都制定了默认值的构造函数也属于默认构造函数。
- **析构函数**：
  作用不是删除对象，是在撤销对象占用的内存之前完成一些清理工作，由于没有函数参数，所以不可以被重载。
- **构造函数、析构函数执行顺序**：
  先构造的后析构，后构造的先析构。相当于一个栈，先进后出。
- **静态数据成员**：
  在内存中只占一份空间，每个对象都可以引用这个静态数据成员。静态数据成员在程序编译时被分配空间，到程序结束时才释放空间。
- **静态成员函数/非静态成员函数**：
  非静态成员函数有this指针，而静态成员函数没有this指针。静态成员函数主要用来访问静态数据成员。
- **提前引用声明**：
  在正式声明一个类之前，先声明一个类名，表示此类稍后声明。目的为了解决“鸡生蛋，蛋生鸡”的问题。
- **保护成员/私有成**员：
  两者的不同之处，在于把保护成员的访问范围扩展到派生类中。

### 运算符

- **自增/减运算符重载函数**：
  如果在自增（自减）运算符重载函数中，增加一个int型形参，就是后置自增（自减）运算符函数。
- **转换构造函数/类型转换函数**：
  在需要的时候，编译系统会自动调用这些函数，建立一个无名的临时对象。将运算符“+”函数重载为友元函数，在进行对象相加时，可以用交换律。将运算符“+”函数重载为类的成员函数，交换律不适用。所以，双目运算符函数重载为友元函数，单目运算符则多重载为成员函数。
- **运算符重载**：
  一般将单目运算符重载为成员函数，将双目运算符重载为友元函数（原因如上一条）

### 继承和多态

- **派生类和基类**：
  派生类是基类的具体化，基类是派生类的抽象；一个派生类可以从一个基类派生，也可以从多个基类派生。构造派生类通常包含三部分：从基类接受成员，调整从基类接受的成员，在声明派生类时增加的成员。构造函数和析构函数不能从基类继承。
- **重名函数覆盖**：
  不同的成员函数，只有在函数名和参数个数相同、类型相匹配的情况下才发生同名覆盖，如果只有函数名相同而参数不同，不会发生同名覆盖，而属于函数重载。
- **虚基类继承**：
  由于虚基类在派生类中只有一份数据成员，所以这份数据成员的初始化必须由派生类直接给出。
  基类和派生类之间的转换：
  只能用子类对象对其基类对象赋值，而不能用基类对象对其子类对象赋值。通过指向基类对象的指针，只能访问派生类中的基类成员，不能访问派生类增加的成员。
- **多态(polymorphism)**：
  具有不同功能的函数可以用同一个函数名
- **虚函数**：
  允许在派生类中重新定义与基类同名的函数，并且可以通过基类指针或引用来访问基类和派生类中的同名函数。在基类用virtual声明成员函数时为虚函数，在类外定义虚函数时，无需再加virtual。当一个成员函数被声明为虚函数后，其派生类中的同名函数都自动成为虚函数。
- **纯虚函数**：
  在声明虚函数时被初始化为0的函数，作用是在基类中为其派生类保留一个函数的名字，以便派生类根据需要对它进行定义。如果在基类中没有保留函数名字，就无法实现多态性。
- **cerr/clog**：
  都是在终端显示器上显示出错信息，但是cerr是不经过缓冲区，直接向显示器输出相关信息，clog中的信息是存放在缓冲区中，缓冲区满后或遇到endl时向显示器输出。

### C++工具

- **异常检测**：
  Catch块是try-catch结构中的一部分，必须紧跟在try块之后，不能单独使用，两者之间不能插入其他语句。

### 指向常量的指针vs常量指针

- const出现在*左边，表述被指物是常量，const出现在*右边，表示指针是常量。如果出现在*两遍，表示被指物和指针两者都是常量
