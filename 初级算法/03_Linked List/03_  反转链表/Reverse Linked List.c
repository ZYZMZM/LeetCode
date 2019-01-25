/*
    算法思想：维持三个指针，分别指向当前节点，前驱节点
    和下一节点
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode *pCur = head;
    struct ListNode *pCurpri = NULL;
    struct ListNode *pReverseHead = NULL;
    while(pCur != NULL)
    {
        struct ListNode * pCurNext = pCur->next;
        if(pCurNext == NULL)
        {
            pReverseHead = pCur;
        }
        pCur->next = pCurpri;
        pCurpri = pCur;
        pCur = pCurNext;
    }
    return pReverseHead;
}