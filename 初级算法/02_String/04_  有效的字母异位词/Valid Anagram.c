/*
    算法思想：本题是数组模拟哈希表的方法，在哈希表中存储第一个串的
    字符 - 字符出现次数的映射，然后遍历第二个串，每遍历到一个字符，
    就减去其次数，最后判断hash表中是否为全0 即可
*/
bool isAnagram(char* s, char* t) {
    if(s == NULL || t == NULL || strlen(s) != strlen(t))
    {
        return false;
    }
    
    int hashMap[256] = {0};
    char *ps = s;
    while(*ps != '\0')
    {
        hashMap[*ps++]++;
    }
    
    char *pt = t;
    while(*pt != '\0')
    {
        hashMap[*pt++]--;
    }
    
    pt = t;
    while(*pt != '\0')
    {
        if(hashMap[*pt] != 0)
        {
            return false;
        }
        else
        {
            pt++;
        }
    }
    return true;
}