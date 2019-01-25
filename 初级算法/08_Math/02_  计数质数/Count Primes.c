/*
    算法思想：采用埃拉斯特尼筛选法：https://blog.csdn.net/u012965373/article/details/52248039
    即遍历到i，循环删除i的所有倍数，并标记为false，最后素数全为true
*/
int countPrimes(int n) {
    int *Num = (int *)malloc(sizeof(int) * (n + 1));
    for(int i = 0; i < n ; i++)
    {
        Num[i] = i;
    }
    
    bool *IsPrime = (bool *)malloc(sizeof(bool) * (n + 1));
    memset(IsPrime,true,sizeof(bool) * (n + 1));
    
    IsPrime[0] = false;
    IsPrime[1] = false;
    
    int CurNum = 2;
    while(CurNum * CurNum < n)
    {
        if(IsPrime[CurNum])
        {
            int CurNumSqu = CurNum * CurNum;
            while(CurNumSqu < n)   // 循环标记 CurNum 的所有倍数
            {
                IsPrime[CurNumSqu] = false;
                CurNumSqu += CurNum;   // 得到 CurNum 下一个倍数
            }
        }
        CurNum++;
    }
    
    int len = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(IsPrime[i])
        {
            len++;
        }
    }
    return len;    
}