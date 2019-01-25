/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */


//  qsort不能对含有-2147483648元素的整型数组进行排序
//  自写快排，注意递归的写法

int Partition(int *arr,int low,int high)
{
    int temp = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= temp){high--;}
        arr[low] = arr[high];
        while(low < high && arr[low] <= temp){low++;}
        arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
}

void Qsort(int *arr,int low,int high)
{
    int k = Partition(arr,low,high);
    if(low < k - 1){Qsort(arr,low,k-1);}    
    if(high > k + 1){Qsort(arr,k+1,high);}
}

// int Compare(const void *num1, const void *num2)
// {
//     return *(unsigned int *)num1 - *(unsigned int *)num2;
// }
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // qsort(nums1,nums1Size,sizeof(int),Compare);    
    // qsort(nums2,nums2Size,sizeof(int),Compare);
    Qsort(nums1,0,nums1Size - 1);    
    Qsort(nums2,0,nums2Size - 1);

    int *result = (int*)malloc(sizeof(int) * nums2Size);
    int p1 = 0;
    int p2 = 0;
    int newlen = 0;
    while(p1 < nums1Size && p2 < nums2Size)
    {
        if(nums1[p1] == nums2[p2])
        {
            result[newlen++] = nums1[p1];
            p1++;
            p2++;
        }
        else if(nums1[p1] > nums2[p2])
        {
            p2++;
        }
        else
        {
            p1++;
        }
    }
    *returnSize = newlen;
    return result;
}