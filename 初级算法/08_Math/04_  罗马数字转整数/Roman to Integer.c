/*
    算法思想：首先用数组模拟哈希表，存储罗马数字 到 阿拉伯数字的映射
    根据罗马数字的特点，当后一个数字小于等于该数字时，累加，否则减去
    该数字。
*/
int romanToInt(char* s) {
    char Nums[7] = {'I','V','X','L','C','D','M'};    
    int hashMap[256] = {0};
    hashMap[Nums[0]] = 1;
    hashMap[Nums[1]] = 5;
    hashMap[Nums[2]] = 10;
    hashMap[Nums[3]] = 50;
    hashMap[Nums[4]] = 100;
    hashMap[Nums[5]] = 500;
    hashMap[Nums[6]] = 1000;
    
    int length = strlen(s);
    int num = 0;
    for(int i = 0 ; i < length; i++)
    {
        int val = hashMap[s[i]];
        if(i == length - 1 || hashMap[s[i + 1]] <= hashMap[s[i]])
            num += val;
        else
            num -= val;
    }
    return num;
}