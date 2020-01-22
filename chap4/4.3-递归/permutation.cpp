/*
例题记录: 全排列
输出应满足靠前的排列小于靠后的排列，即123、132、213、231、312、321
*/


#include <cstdio>

const int maxn = 11;

int n, P[maxn], hashTable[maxn] = {false}; // P为当前排列，hashTable记录x是否已经在P中

// 当前处理排列的第index位
void generateP(int index){
    if (index == n + 1){ // 递归边界，已处理完P[1]~P[index]
        for (int i=1; i<=n; i++){
            printf("%d", P[i]);
        }
        printf("\n"); // 输出当前排列
        return;
    }
    for (int i=1; i<=n; i++){ // 枚举1~n，将i填入P[index]
        if (hashTable[i] == false){ // 如果i不在P[0]~P[index-1]中
            P[index] = i; // 把x加入排列
            hashTable[i] = true; // 标记x已在排列中
            generateP(index + 1); // 继续处理第index+1位
            hashTable[i] = false; // 已处理完P[index]为i的子问题，应还原状态
        }
    }
}

int main(){
    n = 3; // 遇欲得到长度为3的全排列
    generateP(1); // 从第1位开始填
    return 0;
}
