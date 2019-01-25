/*
    算法思想：本题直接根据题意，思路明确，就是统计各个数字字符连续出现的次数
    即 次数+字符+次数+字符·······
    为了使程序功能明确，划分为3个函数:
    char *CalnNum(char *str)   // 求str的下一个报数
    char *UseFun(char *str,int n)  // 求第n个报数
    char* countAndSay(int n) // 初始化函数
    本题的坑：第一个版本使用了指针代替下标，导致程序混乱，bug太多，于是采用数组下标的
    方式，简洁明了，思路清晰
*/

char *CalnNum(char *str)
{
	int length = strlen(str);
	char *result = (char *)calloc(2 * length , sizeof(char) );
	int i = 0;
	for (; i < length; i++)
	{
		char ch = str[i];
		char len = '1';
		while (i < length && str[i] == str[i + 1])
		{
			i++;
			len++;
		}
		char tmp[3];
		tmp[0] = len;
		tmp[1] = ch;
		tmp[2] = '\0';

		strcat(result,tmp);         // 21  1211  111221 312211
	}
	return result;
}

char *UseFun(char *str,int n)
{
	for (int i = 2; i < n + 1; i++)
	{
		char *result = CalnNum(str);
		str = result;
	}
	return str;
}

char* countAndSay(int n) {
	if (n == 1)
	{
		return "1";
	}
	char *result = UseFun("1",n);
	return result;
}