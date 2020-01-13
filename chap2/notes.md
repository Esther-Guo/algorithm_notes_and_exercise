`include <stdio.h>` 等价于 `include <cstdio>`，推荐后一种  
绝对值在 10<sup>9</sup> 以内的整数均可定义为int型（4 Bytes）。否则使用long long。%d
若long long型数据的初值大于2<sup>31</sup>-1，则后面加LL。  
单精度float的有效精度为6~7位， 双精度double为15~16位。建议浮点数全部使用double存储。%f  
小写字母比大写字母的ASCII值大32。  
字符常量（单个字符）必须用单引号括起来。char %c  
\0 代表空字符，ASCII码为0.  
字符串常量可以用双引号标记并作为初值赋给字符常量**数组**。使用%s输出。  
强制类型转换：(新类型名)变量名  
符号常量（宏替换）：`#define pi 3.14` == `const double pi = 3.14;` 推荐使用const写法  
整型数据相除/，结果向下取整。  
无穷大的数 INF 可以设置为 const int INF = (1 << 30 - 1) 或 0x3fffffff，即2<sup>30</sup>-1。
a << x 左移运算符：将数a按二进制位左移x位。  
n /= (m+1) <==> n = n/(m+1)  
|数据类型 | 格式符 |
|:---|----|
|int|%d|
|long long|%lld|
|float|%f|
|double|%lf|
|char|%c|
|string|%s| 
ps: 只有 scanf("%s", str) 不需要&取址符  
使用printf时double的输出格式符是%f，需另外记忆.  
需要输出%或\时要额外再加一个%或\。  
%md可以使不足m位的整型数据以m位进行右对齐输出，高位使用空格补齐。已超出m位的数据输出不变。  
%0md将不足m位数据的高位用0补齐。  
%.mf让浮点数保留m位小数输出（四舍六入五成双）。  
注释符：/**/ or //  
别名： typedef long long LL; //可以使用LL代替long long  
常用math函数：
* fabs(double) 取绝对值
* floor(double) ceil(double) 向下/上取整，返回double型 floor(-5.2) = -6
* pow(double r, double p) 返回r<sup>p</sup>
* sqrt(double x) 返回算术平方根
* log(double) 返回以自然对数为底的对数 log(1.0) = 0.000000 若底数为其他值，则使用换底公式转换为以自然对数为底。log<sub>a</sub>b = log<sub>e</sub>b / log<sub>e</sub>a
* sin(double), sin(double), tan(double) 参数需为弧度制. pi的精确值为 asin(-1.0)
* round(double) 返回四舍五入的double型整数，可以使用(int)取整。
如果数组一开始没有赋初值，数组中的每个元素都会是一个随机数。int a[10] = {0} or int a[10] = {} 将所有元素初始化为0.  
如果数组较大（10<sup>6</sup>），应将数组定义在主函数外。  
使用memset对数组元素赋相同初值：#include <cstring> memset(数组名，值，sizeof(数组名)) 此方法只建议赋0或-1.  
gets(), puts()用于输入输出一个字符串，识别\n作为结束标志。  
使用以下函数时需要在开头加 #include <cstring>
* strlen(字符数组) 得到字符数组第一个\0前字符的个数
* strcmp(字符数组1, 字符数组2) 根据字典序比较，若数组1<数组2，则返回负整数；相同则返回0；>则返回正整数。 
* strcpy(字符数组1, 字符数组2) 把字符数组2赋值给字符数组1，包括末尾\0。
* strcat(字符数组1, 字符数组2) 把字符数组2接到字符数组1后。
sscanf(str, "%d", &n); 把str的内容以%d的形式放入n中。
sprintf(str, "%d", n); 把n的内容以%d的形式放入str中。printf("%s", str);将str输出。  
数组作为参数，数组的第一维不需要填写长度，调用时只填数组名。且函数中对数组的修改就是对原数组的修改。  
数组不可以作为返回类型。  
指针变量用来存放指针。给指针变量赋值的一般方式是将变量的地址取出来，赋给对应类型的指针变量。int* p = &a; -> a==*p  
对于一个int*型的指针变量p来说，p+1是指p所指的int型变量的下一个int型变量的地址。  
对于int型数组，其中的元素在地址上都是连续的。取地址：&arr[i]  
数组名称可以作为首个元素的地址使用，即 arr = &arr[0], arr+i = &arr[i]  
两个int型指针相减，得到的结果是两个指针之间差了几个int元素，而非地址直接相减。  
指针变量作为函数参数，如果该指针对应的元素在函数中被修改，该元素就真的被修改了。  
引用的作用是给原变量起别名，不产生副本，对引用的操作就是对原变量的操作。  
构造函数：不需要返回类型，函数名与结构体名相同。  
避免浮点数误差：
```
const double eps=1e-8;
const double pi=acos(-1.0);
#define Equ(a,b) ((fabs((a)-(b)))<(eps))
#define More(a,b) (((a)-(b))>(eps))
#define Less(a,b) (((a)-(b))<(-eps))
#define MoreEqu(a,b) (((a)-(b))>(-eps))
#define LessEqu(a,b) (((a)-(b))<(eps))
```
多点测试的三种读数据方式：
* 未给定输入的结束条件：while...EOF
```
while(scanf("%d", &n) != EOF) {...}
while(scanf("%s", str) != EOF) {...} \\string_1
while(gets(str) != NULL) {...} \\ string_2
```
* 当输入满足某条件时终止：while...break（在while内部判断输入是否满足终止条件，满足则break）
```while(scanf("%d %d", &a, &b), a||b) {...} \\ 若a,b至少一个不为零，循环继续
* 输入首行给出测试数据组数，再给出各组数据：while(T--) {...}
```
scanf("%d", &T);
while(T--) {...} \\每次循环解决一组数据的输入和输出
```

