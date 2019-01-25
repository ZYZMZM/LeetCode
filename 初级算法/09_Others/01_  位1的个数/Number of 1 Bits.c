/*
    算法思想：两种方法
    1、普通的算法，需要循环32次(n的位数)
    2、利用位运算的技巧，n中有几个1就循环几次
*/

// int hammingWeight(uint32_t n) {
//     int len = 0;
//     int flag = 1;
//     while(flag)  // flag != 0
//     {
//         if(n & flag)    //  n & flag != 0
//         {
//             len++;
//         }
//         flag <<= 1;
//     }
//     return len;
// }

int hammingWeight(uint32_t n) {
    int len = 0;
    while(n)
    {
        len++;
        n = n & n-1;
    }
    return len;
}