/*
    算法思想：本题有多种解法
    循环、递归、找到最大3的次方、使用对数判断
*/

//==========Solution1 : 循环法，时间效率较好===========
bool isPowerOfThree(int n) {
    if(n <= 0)
    {
       return false;
    }
    
    while(n > 1)
    {
        if(n % 3 != 0)
            return false;
        
        n /= 3;
    }
    return true;
}



//==========Solution2 : 递归法，代码简洁，但时间效率差=============

// bool isPowerOfThree(int n) {
//     if(n <= 0)
//         return false;
    
//     if(n == 1)
//     {
//         return true;
//     }
    
//     return ((n % 3 == 0) && isPowerOfThree(n / 3));
// }






//===========Solution3 : 找到最大3的次方，时间效率最高=============
/*    
    算法思想:由于int型正整数的范围是 0 ~ 2^31，在此范围中
    允许的最大的3的次方数为3 ^ 19 = 1162261467，那么我们
    只要判断该数能否被n整除即可
*/

// bool isPowerOfThree(int n) {
//     return (n > 0 && 1162261467 % n == 0);
// }






//===========Solution4 : 使用对数求解===============
/*
    算法思想：若n为3的次方,则对n取以3为底的对数一定是一个整数，即次方数
    则只需要判断结果是否为整数即可。
*/

// bool isPowerOfThree(int n) {
//     double result = log10(n) / log10(3);
//     return ((int)result == result) ? true : false;
// }