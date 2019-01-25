/*
    算法思想：本题需要设置三个变量：之前最小的价格，之前最大的利润，
    当下的利润，每次遍历可能更新最小价格，将当前的利润与之前的最大
    利润比较，最后若利润为负，则返回0；否则，返回最大利润。
*/
int maxProfit(int* prices, int pricesSize) {
    if(prices == NULL || pricesSize < 2)
    {
        return 0;
    }
    
    int min = prices[0];
    int maxDiff = prices[1] - min;
    
    for(int i = 1; i < pricesSize; i++)
    {
        if(prices[i-1] < min)
        {
            min = prices[i-1];
        }
        
        int curDiff = prices[i] - min;
        if(curDiff > maxDiff)
        {
            maxDiff = curDiff;
        }
    }
    if(maxDiff < 0) // 交易没有完成返回 0 
        return 0;
    
    return maxDiff;
}