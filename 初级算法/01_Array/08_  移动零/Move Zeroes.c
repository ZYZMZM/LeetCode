// 算法思想：先统计0的个数，然后把非零元素前移，最后填充0即可

void moveZeroes(int* nums, int numsSize) {
    int ZeroNum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 0)
            ZeroNum++;
    }
    int index = 0; 
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
           nums[index++] = nums[i];
        }
    }
    for(int i = numsSize - ZeroNum; i < numsSize ; i++)
    {
        nums[i] = 0;
    }
}