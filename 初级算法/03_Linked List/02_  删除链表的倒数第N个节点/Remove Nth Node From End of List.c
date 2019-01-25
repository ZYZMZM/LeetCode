/*
    算法思想：链表的经典题型，即维持两个指针，让快指针
    向前走N-1步，然后慢指针从表头开始，与快指针同步遍历
    链表，若快指针指向最后一个结点，则慢指针所指的节点就是
    倒数第N个节点,然后将情况分为要删除的是头节点，尾节点和
    中间节点的不同情况，进行节点的删除
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* pFast = head;
    struct ListNode* pSlow = head;
    
    for(int i = 0; i < n - 1; i++)
    {
        pFast = pFast->next;
    }
    
    while(pFast->next != NULL)
    {
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    
    struct ListNode* pDel = pSlow;    
    struct ListNode* pDelNext = pSlow->next;

    if(pDel == head)    // 头节点
    {
        head = head->next;
    }
    else if(pDel->next != NULL)  //  非尾节点
    {
        pDel->val = pDelNext->val;
        pDel->next = pDelNext->next;
        free(pDelNext);
    }
    else // 尾节点
    {
        struct ListNode* p = head;
        while(p->next != pDel)
        {
            p = p->next;
        }
        p->next = NULL;
        free(pDel);
    }
    return head;
}
