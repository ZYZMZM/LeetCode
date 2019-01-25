/*
    算法思想：直接根据题意写出程序即可
    遇到的坑：由于动态开辟了二维数组，我们在使用一维时要再次为一维的动态开辟内存空间;
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **result = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i < n; i++)
    {
        if((i + 1) % 3 == 0 && (i + 1) % 5 == 0)
        {
            result[i] = (char *)malloc(sizeof(char) * 9);
            result[i] = "FizzBuzz";
            continue;
        }
        else if((i + 1) % 3 == 0)
        {
            result[i] = (char *)malloc(sizeof(char) * 5);
            result[i] = "Fizz";
            continue;
        }
        else if((i + 1) % 5 == 0)
        {
            result[i] = (char *)malloc(sizeof(char) * 5);
            result[i] = "Buzz";
            continue;
        }
        else
        {
            result[i] = (char *)malloc(sizeof(char) * 9);
            sprintf(result[i], "%d", i+1);
            continue;
        }
    }
    *returnSize = n;
    return result;
}