// http://codeup.cn/problem.php?cid=100000608&pid=4

/*
自己没思路，本题代码来自网络。其实就是模拟一个进出栈的过程，
甚至无需真的建立栈。配合递归即可完成。
*/

#include <cstdio>
int num = 0;
int n;
void Stack(int inWait,int outWait,int outs){
    if(n == outs){ // 所有元素均已出栈
        num++;
        return ;
    }
    if(inWait > 0) // 尚未进栈的元素个数
        Stack(inWait-1,outWait+1,outs);
    if(outWait > 0) // 尚未出栈的元素个数
        Stack(inWait,outWait-1,outs+1);
}

int main(){
    scanf("%d",&n);
    Stack(n, 0, 0);
    printf("%d\n",num);
    return 0;
}

