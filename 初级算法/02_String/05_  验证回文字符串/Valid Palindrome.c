/*
    算法思想：由于题目要求回文串只包含字母和数字字符，则
    调用C库函数isalnum来判断字符变量是否为字母或数字
    题目要求忽略字母的大小写，我们调用C库函数tolower
    将所有大写字母转换为小写
    整体思想，为双指针分别从头尾向中间遍历，遇到合法字符
    开始匹配，匹配不成功直接返回false
*/

bool isPalindrome(char* s) {
    if(s == NULL) return false;
    if(*s == "") return true;
    
    for(int i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
    }
    
    char *pBegin = s;
    char *pEnd = s + strlen(s) - 1;
    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && !isalnum(*pBegin))
            pBegin++;
        
        while(pBegin < pEnd && !isalnum(*pEnd))
            pEnd--;
        
        while(pBegin < pEnd && *pBegin != *pEnd)
        {
            return false;
        }
        pBegin++;
        pEnd--;
    }
    return true;
}