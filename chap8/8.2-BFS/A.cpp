// http://codeup.cn/problem.php?cid=100000609&pid=0

/*
显示答案错误0，但能通过给的例子。鉴于通过率极低跳过本题。
*/

#include <cstdio>

int a, b, goal;
int current_a = 0, current_b = 0;

void fill_b() {
    current_b = b;
    printf("fill B\n");
}

void empty_a() {
    current_a = 0;
    printf("empty A\n");
}

void pour_ba() {
    if (current_b > a - current_a) {
        current_b -= (a - current_a);
        current_a = a;
    }
    else {
        current_a += current_b;
        current_b = 0;
    }
    printf("pour B A\n");
}

int main() {
    while (scanf("%d %d %d", &a, &b, &goal) != EOF) {
        while (current_a != goal && current_b != goal) {
            if (current_b == 0) fill_b();
            else if (current_a == a) empty_a();
            else pour_ba();
        }
        printf("success\n");
    }

    return 0;
}

