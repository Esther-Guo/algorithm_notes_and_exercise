#include <cstdio>
#include <algorithm>

using namespace std;

// 取两个数的最值，支持浮点数
max(x,y);
min(x,y);
max(x,max(y,z)); // 3个数的情况
// 取绝对值
int x; 
abs(x); // 必须是int型，浮点型应使用math.h下的fabs

// 交换两个数
swap(x, y);

// 反转
reverse(it, it2); // 将该范围内元素反转（左闭右开）

// 全排列
int a[10] = {1,2,3};
// 输出123的全排列
do {
    cout << a[0] << a[2] << a[3] << endl;
} while (next_permutation(a, a+3));

// 填充
int a[5] = {1,2,3,4,5};
fill(a, a+3, 233); // 将a[0]~a[2]赋值为233

// 查找元素的上限下限(仅限有序情况)
int a[10] = {1,2,2,3,3,3,5,5,5,5};
int *lowerPos = lower_bound(a, a+10, -1); // 在a[0]~a[9]范围寻找大于等于-1的第一个元素的位置，没有则返回可插入位置
int *upperPos = upper_bound(a, a+10, -1); // 在a[0]~a[9]范围寻找大于-1的第一个元素的位置，没有则返回可插入位置

int pos = lower_bound(a, a+10, -1) - a; // 第一个-1的下标
int pos = upper_bound(a, a+10, -1) - a; // 最后一个-1的下标
