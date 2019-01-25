// 算法思想：利润最大化，即有利润就交易
int maxProfit(int* prices, int pricesSize) {
    if(prices == NULL || pricesSize <= 0)
    {
        return 0;
    }
    int maxValue = 0;
    for(int i = 0; i < pricesSize - 1; i++)   //注意边界问题
    {
        if(prices[i] < prices[i + 1])
        {
            maxValue += prices[i+1] - prices[i];
        }
    }
    return maxValue;
}