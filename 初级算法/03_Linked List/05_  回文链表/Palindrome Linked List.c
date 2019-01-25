/*
    算法思想：首先先得到链表长度,边遍历边逆置，逆置一半len/2，定义双指针， 
    如果链表长为奇数，那么pCur指向中间位置，直接跳过即可判断对应位置
    元素是否相等，直至两个指针走向空即可
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* pFirst = head;
    int len = 0;
    while(pFirst != NULL)
    {
        pFirst = pFirst->next;
        len++;
    }
    
    if(len == 1)
        return true;
    
    struct ListNode* pCur = head;
    struct ListNode* pCurpri = NULL;
    int i = 0;
    while(i < len / 2)
    {
        struct ListNode* pCurNext = pCur->next;
        pCur->next = pCurpri;
        pCurpri = pCur;
        pCur = pCurNext;
        i++;
    }
    
    if(len % 2 != 0)
    {
        pCur = pCur->next;  // 如果链表长为奇数，那么pCur指向中间位置，直接跳过即可
    }
    
    while(pCurpri != NULL && pCur != NULL)
    {
        if(pCurpri->val != pCur->val)
        {
            return false;
            break;
        }
        pCurpri = pCurpri->next;
        pCur = pCur->next;
    }
    
    return true;
}