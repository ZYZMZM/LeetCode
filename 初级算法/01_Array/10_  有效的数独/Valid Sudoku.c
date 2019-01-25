// 使用数组模拟hash表，分别进行每一行、每一列和各个矩阵的数独判断
// 对于行列来讲，较为简单，将控制元素的i、j变量互换即可
// 对于3 * 3的元素矩阵，使用公式 [i + k / 3 * 3][j + k % 3 * 3] 
// 得到元素，为本题的一个小技巧
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int hashMap[256] = {0};
    
    // 判断每一行
    for(int i = 0 ; i < boardRowSize; i++)
    {
        memset(hashMap,0,sizeof(int) * 256);
        for(int j = 0; j < boardColSize;j++)
        {
            hashMap[board[i][j]]++;
            if(board[i][j] != '.' && hashMap[board[i][j]] > 1)
                return false;
        }
    }
    
    // 判断每一列
    for(int i = 0 ; i < boardColSize; i++)
    {
        memset(hashMap,0,sizeof(int) * 256);
        for(int j = 0; j < boardRowSize;j++)
        {
            hashMap[board[j][i]]++;
            if(board[j][i] != '.' && hashMap[board[j][i]] > 1)
                return false;
        }
    }   
    
    // 判断3 * 3 矩阵
    for(int k = 0; k < 9; k++)
    {
        memset(hashMap,0,sizeof(int) * 256);
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                hashMap[board[i + k / 3 * 3][j + k % 3 * 3]]++;
            if(board[i + k / 3 * 3][j + k % 3 * 3] != '.' && hashMap[board[i + k / 3 * 3][j + k % 3 * 3]] > 1)
                return false;
            }
        }
    }
    
    return true;   
}