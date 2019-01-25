/*
    算法思想：初次拿到题目，由于题目要求尽可能少的调用API函数，
    于是采用高效的搜索算法 二分查找法,为了防止溢出,采用分别除
    2相加的方法,由于low+high可能会溢出
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    int low = 1;
    int high = n;
    int middle = 0;
    while(low < high)
    {
        middle = high / 2 + low / 2;// 为了防止溢出,采用分别除2相加的方法,由于low+high可能会溢出
        if(isBadVersion(middle))
        {
            high = middle;
        }
        else
        {
            low = middle + 1;
        }
    }
    return low;
}