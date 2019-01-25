/*
    算法思想：由于nums1 有足够的空间来保存 nums2 中的元素，
    所以我们将两个有序数组从后向前合并，由于数组是有序的，
    则较大元素一定在数组尾部先被合并
*/
void merge(int* nums1, int m, int* nums2, int n) {
    
    while(m > 0 && n > 0)
    {
        if(nums1[m - 1] > nums2[n - 1])
        {
           nums1[m + n - 1] = nums1[m - 1];
            m--;
        }
        else
        {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }
    if(n != 0)
    {
        while(n != 0)
        {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }
}