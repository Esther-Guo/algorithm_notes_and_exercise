`include <stdio.h>` 等价于 `include <cstdio>`，推荐后一种  
绝对值在 $10^9$ 以内的整数均可定义为int型（4 Bytes）。否则使用long long。%d
若long long型数据的初值大于$2^31-1$，则后面加LL。  
单精度float的有效精度为6~7位， 双精度double为15~16位。建议浮点数全部使用double存储。%f  
小写字母比大写字母的ASCII值大32。  
字符常量（单个字符）必须用单引号括起来。char %c  
\0 代表空字符，ASCII码为0.  
字符串常量可以用双引号标记并作为初值赋给字符常量**数组**。使用%s输出。  
强制类型转换：(新类型名)变量名  
符号常量（宏替换）：`#define pi 3.14` == `const double pi = 3.14;` 推荐使用const写法  
整型数据相除/，结果向下取整。  
无穷大的数 INF 可以设置为 const int INF = (1 << 30 - 1) 或 0x3fffffff，即$2^30-1$。
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
* 只有 scanf("%s", str) 不需要&取址符  
使用printf时double的输出格式符是%f，需另外记忆。  
需要输出%或\时要额外再加一个%或\。  
%md可以使不足m位的整型数据以m位进行右对齐输出，高位使用空格补齐。已超出m位的数据输出不变。  
%0md将不足m位数据的高位用0补齐。  
%.mf让浮点数保留m位小数输出（四舍六入五成双）。  
注释符：/**/ or //  
别名： typedef long long LL; //可以使用LL代替long long  
常用math函数：
* fabs(double) 取绝对值
* floor(double) ceil(double) 向下/上取整，返回double型 floor(-5.2) = -6
* pow(double r, double p) 返回$r^p$
* sqrt(double x) 返回算术平方根
* log(double) 返回以自然对数为底的对数 log(1.0) = 0.000000 若底数为其他值，则使用换底公式转换为以自然对数为底。log<sub>a</sub>b = log<sub>e</sub>b / log<sub>e</sub>a
* sin(double), sin(double), tan(double) 参数需为弧度制. pi的精确值为 asin(-1.0)
* round(double) 返回四舍五入的double型整数，可以使用(int)取整。
