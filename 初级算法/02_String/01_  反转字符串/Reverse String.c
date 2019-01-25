// 思路：简单的字符串反转，双指针的典型应用
void reverseString(char* s, int sSize) {
    char *low = s;
    char *high = s + sSize - 1;
    while(low < high)
    {
        char tmp = *low;
        *low = *high;
        *high = tmp;
        low++;
        high--;
    }
}