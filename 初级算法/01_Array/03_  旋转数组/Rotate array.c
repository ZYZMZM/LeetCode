/*
    算法：三次交换法
    心得：初次拿到题目，与左旋数组的思想类似，但本题更为关键的是需要注意边界，由于
    是从数组后部向首部转移，首先是数组长度为1时，无论怎样旋转，数组都保持不变，
    当k大于数组长度时，需要注意数组越界问题，我们将k模数组长度（减去也可以）即可
*/
void Reverse(int* nums,int index1,int index2)
{
    while(index1 <= index2)
    {
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
        index1++;
        index2--;
    }
}
void rotate(int* nums, int numsSize, int k) {
     if(nums == NULL || numsSize <= 0)
     {
         return;
     }
	 if (numsSize != 1)
	 {
		 if (k > numsSize)
		 {
			 k %= numsSize;
		 }
		 int firstStart = 0;
		 int firstEnd = (numsSize - k - 1) % numsSize;
		 int secondStart = numsSize - k;
		 int secondEnd = numsSize - 1;

		 Reverse(nums,firstStart,firstEnd); 
		 Reverse(nums,secondStart,secondEnd);
		 Reverse(nums,firstStart,secondEnd);
	 }
}