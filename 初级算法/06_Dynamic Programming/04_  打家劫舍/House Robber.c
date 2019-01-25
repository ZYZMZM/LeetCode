/*
    算法思想：打家劫舍属于一维动态规划，思路就是动态规划基本思想：
    多阶段最优化决策解决问题，我们对每一个元素当前能取得的最大金
    额存入数组maxValue中，从2号下标开始maxvalue[i-2]的值加上当
    前元素nums[i]，与maxvalue[i-1]进行比较,将大值存入maxValue[i]
    中即可，最后将maxValue[numsSize-1]返回
*/

int max(int num1,int num2)
{
    return num1 > num2 ? num1 : num2;
}
int rob(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(numsSize == 2)
        return max(nums[0],nums[1]);
    
    int *maxValue = (int *)malloc(sizeof(int) * numsSize);
    
    maxValue[0] = nums[0];
    maxValue[1] = max(nums[0],nums[1]);
    
    for(int i = 2 ; i < numsSize; i++)
    {
        maxValue[i] = max(maxValue[i-2] + nums[i],maxValue[i-1]);
    }
    return maxValue[numsSize - 1];
}