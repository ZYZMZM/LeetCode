/*
    算法思想：关于整数的反转问题，反转后的每一位数字都是原数字 mod10 之后得出，
    原数字在除10，本题还需考虑输入数字为负数的问题,还有反转之后整数溢出的问题
    2^31-1=2147483647,-2^31=-2147483648
*/

int reverse(int x) {
    int result = 0;
    int flag = 0;
    //int oldResult = 0;
    
    // if(x < 0)
    // {
    //     flag = 1; 
    // }
        
    while (x != 0)
    {
        int modnum = x % 10; 
      
        if(result > INT_MAX / 10 || result == INT_MAX / 10 && modnum > 7){return 0 ;}         
        if(result < INT_MIN / 10 || result == INT_MIN / 10 && modnum < -8){return 0 ;} 

        result = 10 * result + modnum;  
        x /= 10;
       
        // if(((result - x % 10) / 10) != oldResult)
        //     return 0;
        //oldResult = result;
    }
    
    // if(flag)
    //     result *= -1;
    
    return (int)result;
}