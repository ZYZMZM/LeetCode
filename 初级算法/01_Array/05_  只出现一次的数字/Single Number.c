/*  算法思想：巧妙使用位运算解决,根据异或运算的
    性质，将所有数字异或后，相同的数字抵消，剩下
    的数字即为只出现了一次的数字
*/
int singleNumber(int* nums, int numsSize) {
    if(nums == NULL || numsSize <= 0)
    {
        return -1;
    }
    int result = 0;
    for(int i = 0; i < numsSize; i++)
    {
        result ^= nums[i];
    }
    return result;
}