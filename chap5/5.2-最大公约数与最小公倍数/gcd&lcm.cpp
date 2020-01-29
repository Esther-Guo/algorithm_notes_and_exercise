// 最大公约数 greatest common divisor
int gcd(int a, int b){
    if (b==0) return a; // 任何数和0的最大公约数是a
    else return (b, a%b); // 辗转相除法
}

//最小公倍数 least common multiple
lcm = a/gcd*b // 先做除法避免溢出