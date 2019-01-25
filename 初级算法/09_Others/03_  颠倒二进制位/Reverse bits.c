/*
    算法思想：通过右移n依次获取n的末位,
    设置为result的末位，左移result实现颠倒
*/
uint32_t reverseBits(uint32_t n) {
    int result = 0;
    for(int i = 0; i < 32; i++)
    {
        result <<= 1;   // 左移实现颠倒
        result += n & 1;   // 获取n的末位
        n >>= 1;    // n右移依次获取高位
    }
    return result;
}