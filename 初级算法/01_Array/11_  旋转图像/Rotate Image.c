/* 算法思想：使用临时变量保存一个元素，采用四次交换法，将原矩阵中每一轮的元素都旋转到对应位置
    [1,2,3],         [7,2,1],            [7,4,1],
    [4,5,6],   == >  [4,5,6],    ==>     [8,5,2],
    [7,8,9]          [9,8,3]             [9,6,3]
*/

// void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
//     int n = matrixRowSize;
//     for(int i = 0; i < n / 2; i++)
//     {
//         for(int j = i; j < n - 1 - i; j++)
//         {
//             int temp = matrix[i][j];
//             matrix[i][j] = matrix[n - 1 - j][i];            
//             matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
//             matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];            
//             matrix[j][n - 1 - i] = temp;
//         }
//     }
// }

/*
    解法二：采用二次对换，先将矩阵上下翻转，然后按照对角线进行对称交换
*/

void Swap(int *num1,int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int n = matrixRowSize;
    for(int i = 0; i < n / 2; i++)      // 上下翻转
    {
        for(int j = 0; j < n; j++)
        {
            Swap(&matrix[i][j],&matrix[n - 1 - i][j]);
        }
    }
    
    for(int i = 0; i < n; i++)          // 对角线翻转
    {
        for(int j = 0; j < i; j++)
        {
            Swap(&matrix[i][j],&matrix[j][i]);
        }
    }
}