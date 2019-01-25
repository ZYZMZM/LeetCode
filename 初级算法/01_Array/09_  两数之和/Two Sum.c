/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int *)malloc(sizeof(int) * numsSize);
    int IsFind = 0;
    for(int i = 0 ;i < numsSize ; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                IsFind = 1;
                break;
            }
        }
        
        if(IsFind)
            break;
    }
    return result;
}

//以下代码只对正整数输入数组有效
// int Compare(const void *num1, const void *num2)
// {
//     return *(int *)num1 - *(int *)num2;
// }

// int* twoSum(int* nums, int numsSize, int target) {
//     int *result = (int *)malloc(sizeof(int) * numsSize);
//     // 先建立hash表存储映射关系
//     int hash[INT_MAX] = {0};
//     for(int i = 0; i < numsSize ; i++)
//         hash[nums[i]] = i;
//     qsort(nums,numsSize,sizeof(int),Compare);
//     int low = 0;
//     int high = numsSize - 1;
//     while(low < high)
//     {
//         int sum = nums[low] + nums[high];
//         if(sum > target)
//         {
//             high--;
//         }
//         else if(sum < target)
//         {
//             low++;
//         }
//         else
//         {
//             result[0] = hash[nums[low]];
//             result[1] = hash[nums[high]];
//             break;
//         }
//     }
//     return result;
// }