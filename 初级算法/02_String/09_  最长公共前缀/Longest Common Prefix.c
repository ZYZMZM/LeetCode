/*
    算法思想：本题思路清晰简洁，首先要清晰返回的条件，遍历结束和遇到不同字符
    我们先取得字符串数组中所有字符串元素的最小长度，以它来遍历即可
*/
char* longestCommonPrefix(char** strs, int strsSize) {
    char *result = "";   
    int min = INT_MIN;
    
    for(int i = 0; i < strsSize; i++)
    {
        min = min < strlen(strs[i]) ? min : strlen(strs[i]);
    }
    
    int index = 0;
    int Isbreak = 0;
    int IsFind = 0;
    int j = 0;
    
    for( ; j < min ; j++)
    {
       for(int i = 1; i < strsSize; i++)
        {
            if(strs[i][j] != strs[0][j])
            {
                index = j;
                Isbreak = 1;
                break;
            }
            else
            {
               IsFind = 1;
            }
        } 
        
        if(Isbreak)
            break;
    }
    
    if(j == min)
    {
        strs[0][min] = '\0';
        result = strs[0];
        return result; 
    }
    
    if(IsFind)
    {
        strs[0][index] = '\0';
        result = strs[0];
        return result;
    }
    
    return result;
}