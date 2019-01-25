/*
    算法思想：为了提高时间效率，我们采用时间换空间的做法，本题是
    数组模拟哈希表的典型应用，即哈希表中存储  字符 - 字符出现次数
    的映像，可达到O(1)时间的查找
*/
int firstUniqChar(char* s) {
    int result = -1;
    
    int hashMap[256] = {0};
    int i = 0;
    while(s[i] != '\0')
    {
        hashMap[s[i++]]++;
    }
    
    i = 0;
    while(s[i] != '\0')
    {
        if(hashMap[s[i]] == 1)
        {
            result = i;
            break;
        }
        i++;
    }
    return result;
}