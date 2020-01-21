散列核心思想：将元素通过一个函数转换为整数，使得该整数可以尽可能唯一的代表该元素。  
散列函数H：key -> H(key)  
若key为整数，常用散列函数：
* 直接定址法：恒等变换(H(key) = key)或是线性变换(H(key) = a*key+b)
* 平方取中法：取key值平方的中间若干位
* 除留取余法：H(key) = key%mode 一般取表长 TSize = mode = 某素数. 一旦某两个key对应相同的H(key)时,则需要解决冲突。
以下为三种常见的解决冲突方法：(前两种重新计算哈希值，又称为开放定址法)
* 线性探查(linear probing)：不断检查下一个位置是否被占用，如超越表长则回到头部继续探查。此方法容易使元素扎堆。
* 平方探查(quadratic probing)：为了避免扎堆，当H(key)位置被占时，将依次检查：H(key)+1<sup>2</sup>, H(key)-1<sup>2</sup>, H(key)+2<sup>2</sup>, H(key)-2<sup>2</sup>... 如果H(key)+k<sup>2</sup>超越表长，则把H(key)+k<sup>2</sup>对表长取模。如果出现H(key)-k<sup>2</sup><0的情况，则计算((H(key)-k<sup>2</sup>)%TSize+TSize)%TSize(相当于把H(key)-k<sup>2</sup>不断加上TSize直到出现第一个非负数)。
* 链地址法(拉链法)：把所有H(key)值相同的key连接成一条单链表。可以通过遍历单链表的方式寻找所有H(key)相同的key。
STL库中的map可以直接使用哈希的功能，一般无需自己解决冲突。  
#### 字符串hash
假设均由大写字母组成，将A~Z映射为0~25.接下来将26进制转换为10进制，即可保证哈希值的唯一性。转换后的整数最大值为26<sup>len</sup>-1. 代码如下：
```
int hashFunc(char s[], int len) {
    int id = 0;
    for (int i = 0; i < len; i++) {
        id = id * 26 + (s[i] - 'A');
    }
    return id;
}
```
如果涉及到小写字母，则将a~z映射为26~51，转换为52进制，再向十进制转换。对于数字，可以类似处理为62进制。