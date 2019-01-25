/*
    算法思想：求连续子数组最大和问题，要摒弃传统解法，寻求高效的算法
    我们可以通过实例来找到通用的规律，定义两个变量，一个用来累计当前
    元素累加后的总和，一个用来保存之前的最大和，若当前和小于0，则不进行
    累加，直接将当前元素存入累加和中，每轮都判断当前和与最大和的大小关系
    然后更新最大和，最后返回即可
*/
int maxSubArray(int* nums, int numsSize) {
    
    int Curmax = 0;
    int MaxValue = 0x80000000;
    for(int i = 0; i < numsSize; i++)
    {
        if(Curmax < 0)
        {
            Curmax = nums[i];
            
        }
        else
        {
            Curmax += nums[i];
        }
        
        if(Curmax > MaxValue)
        {
            MaxValue = Curmax;
        }
    }
    return MaxValue;
}