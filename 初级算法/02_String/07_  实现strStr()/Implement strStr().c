/*
    算法思想：题目已经描述的非常清楚了，各种情况的处理方式及返回的结果
    直接上手编程即可，还是要注意大整数溢出的问题，采用在“整数反转”中
    相同的处理方式判断是否溢出
*/
int myAtoi(char* str) {
    char *pStr = str;
    int flag = 0;
    
    if(*pStr == ' ' && *pStr != '\0')
    {
        pStr++;
        while(*pStr == ' ' && *pStr != '\0')
        {
            pStr++;
        }
    }

    if(!isdigit(*pStr) && *pStr != '+' && *pStr != '-' && *pStr != '\0')
    {
        return 0;
    }

    if(*pStr == '-' && *pStr != '\0')
    {
        flag = 1;
        pStr++;
    }
    else if(*pStr == '+' && *pStr != '\0')
    {
        pStr++;
    }
    
    int result = 0;
    while(*pStr != '\0')
    {
        int num = *pStr - '0';
        if(isdigit(*pStr))
        {
            if(!flag && (result > INT_MAX / 10 || result == INT_MAX / 10 && num > 7))   
                return INT_MAX;         
            
            if(flag && ((-1) * result < INT_MIN / 10 || ( (-1) * result == INT_MIN / 10 && (-1) * num < -8)))   
                return INT_MIN ;
            result = result * 10 + *pStr - '0';
            
            pStr++;
        }
        else
        {
            break;
        }
    }
	if (flag)
	{
		return (-1) *result;
	}
	else
	{
		return result;
	}
}