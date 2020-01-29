struct Fraction {
    int up, down; // 分子，分母
};

// 化简
Fraction reduction(Fraction result){
    if (result.down < 0) { // 对于负分数，统一令分子为负数
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0) result.up = 1; // 对于分子为0的分数，统一令分母为1
    else { // 约分
        int d = gcd(abs(result.up), abs(result.down)); //求出最大公约数
        result.up /= d;
        result.down /= d;
    }
    return result;
}