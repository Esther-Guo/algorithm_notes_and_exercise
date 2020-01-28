#include <cstdio>
#include <cstdlib> // attention
#include <ctime> // attention

int main(){
    srand((unsigned)time(NULL)); // attention 初始化随机种子
    for (int i=0;i<10;i++){
        printf("%d ", rand()); // generate 10 random numbers in range [0, RANDMAX]
    }
}

// 如果需要生成[a,b]范围内随机数，使用 rand()%(b-a+1)+a