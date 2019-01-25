/*
    算法思想：将数组排序，直接判断是否有前后两个
    元素相等的，若有，则表示存在重复元素
*/
int Compare(const void *num1,const void *num2)
{
    return *(int *)num1 - *(int *)num2;
}

bool containsDuplicate(int* nums, int numsSize) {
    if(nums == NULL || numsSize <= 1)
        return false;
    
    qsort(nums,numsSize,sizeof(int),Compare);
    for(int i = 0; i < numsSize;i++)
    {
        if(nums[i] == nums[i+1])
        {
            return true;
        }
    }
    return false;
}
