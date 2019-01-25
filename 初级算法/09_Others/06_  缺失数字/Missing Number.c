/*
    算法思想：先计算0···n这n+1个数的和，然后计算nums序列的和，
    两者之差即为缺失的数字
*/
int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    int numsSum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        sum += i + 1;  // sum 用来累加0··n 共n+1个数的和
        numsSum += nums[i];  // numsSum用来累加nums序列和
    }
    return sum - numsSum;
}