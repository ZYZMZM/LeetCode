/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;
    for(int i = digitsSize - 1; i >=0 ; i--)
    {
        if(digits[i] < 9)
        {
            digits[i] += 1;
            return digits;
        }
        else
        {
            digits[i] = 0;
        }
    }
    
    // 之前全为9，全部进位的情况, 重新创建数组返回
    int *result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    result[0] = 1;
    for(int i = 1; i < digitsSize + 1; i++)
        result[i] = 0;
    *returnSize = digitsSize + 1;
    return result;
}