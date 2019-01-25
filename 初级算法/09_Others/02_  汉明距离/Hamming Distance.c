/*
    算法思想：汉明距离表示两个数字对应二进制位不同的位置的数目
    那我们根据位运算的技巧，对两个数字进行异或运算，并统计结果
    为1的个数，那么这个数目就是汉明距离。
*/
int hammingDistance(int x, int y) {
    int num = x ^ y;
    int dis = 0;
    while(num)
    {
        dis++;
        num = num & (num - 1);
    }
    return dis;
}