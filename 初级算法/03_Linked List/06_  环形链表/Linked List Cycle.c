/*
    算法思想：判断链表是否有环，也是双指针解法，定义快指针和慢指针，快指针比
    慢指针多走两步，如果慢指针能追上快指针，则链表有环
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL)
    {
        return false;
    }
    
    struct ListNode *pSlow = head;    
    struct ListNode *pFast = pSlow->next;

    while(pSlow != NULL && pFast != NULL && pSlow != pFast)
    {
        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast != NULL)
        {
            pFast = pFast->next;
        }
        else
        {
            break;
        }
    }
    if(pSlow == NULL || pFast == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}