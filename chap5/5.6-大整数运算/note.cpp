// 采用数组记录大整数：按照从低位至高位的顺序(先按照字符串读入，再逆序赋给bign结构体)
struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

// 字符串转bign
bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for (int i=0; i<a.len; i++){
        a.d[i] = str[a.len-i-1] - '0'; // -'0'即可转int
    }
    return a;
}

// 比较两个bign大小: 首先比较长度，长的更大。长度相同则从高位开始比较
int compare (bign a, bign b){
    if (a.len > b.len) return 1; // a大返回1
    else if (a.len < b.len) return -1; // a小返回-1
    else {
        for (int i=a.len-1; i>=0; i--){
            if (a.d[i] > b.d[i]) return 1;
            else if (a.d[i] < b.d[i]) return -1;
        }
        return 0; // 相等
    }
}

// 高精度加法（均为正数，否则应处理负号）
bign add(bign a, bign b){
    bign c;
    int carry = 0; // 进位
    for (int i=0; i<a.len || i<b.len; i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) c.d[c.len++] = carry; // 处理最后的进位
    return c;
}

// 高精度减法（使用前应先比较两数大小，绝对值大的减绝对值小的，结果应为负就加上负号）
bign sub(bign a, bign b){
    bign c;
    for (int i=0; i<a.len || i<b.len; i++){
        if (a.d[i] < b.d[i]){
            a.d[i+1]--; // 借位
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len >= 2 && c.d[c.len-1] == 0){ //除去高位多余的0，但仍应保证剩下一位
        c.len--;
    }
    return c;
}

// 高精度与低精度(int)的乘法: 将int当做一个整体
bign multi(bign a, int b){
    bign c;
    int carry = 0;
    for (int i=0; i<a.len; i++){
        int temp = a.d[i]*b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp/10;
    }
    while (carry != 0){ // 进位可能不止一位，所以用while
        c.d[c.len++] = carry % 10;
        carry /= 10; 
    }
    return c;
}

// 高精度与低精度(int)的除法
bign divide(bign a, int b, int& r){ // r为余数
    bign c;
    c.len = a.len; // 商和被除数按位对应
    for (int i=a.len-1; i>=0; i--){ // 从高位开始
        r = r*10 + a.d[i];
        if (r<b) c.d[i] = 0; // 不够除
        else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while (c.len >= 2 && c.d[c.len-1] == 0){
        c.len--;
    }
    return c;
}