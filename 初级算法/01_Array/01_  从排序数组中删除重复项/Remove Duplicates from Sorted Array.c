// 算法思想：标记不同元素个数即为要覆盖元素的下标值

int removeDuplicates(int* nums, int numsSize) {
    if(nums == NULL || numsSize <= 0)
    {
          return 0;
    }
       
    int index = 0;
    for(int i = 0;i < numsSize;i++)
    {
        if(nums[i] != nums[index])
        {
            index++;
            nums[index] = nums[i] ;
        }
    }
    return index + 1;
}