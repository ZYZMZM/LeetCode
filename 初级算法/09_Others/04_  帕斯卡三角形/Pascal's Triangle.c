/*
    算法思想：本题实质就是求杨辉三角的前n行,核心在于杨辉
    三角公式——arr[i][j] = arr[i-1][j-1] + arr[i-1][j]
*/
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
  
    int **result = (int **)malloc(sizeof(int*) *numRows);
    *columnSizes = (int *)malloc(sizeof(int) *numRows);

    for(int i = 0; i < numRows ; i++)
    {
        result[i] = (int *)malloc(sizeof(int) * (i + 1));
        result[i][0] = 1;
        result[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        (*columnSizes)[i] = i + 1;
    }
    return result;
}