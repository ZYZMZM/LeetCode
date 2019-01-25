/*
    算法思想：合并两个有序链表有递归和非递归两种方法
    非递归就是建立新链表存储有序链表，首先判断数据节点小的
    链表，将其直接链入新链表，然后定义指向新链表首节点的
    指针，开始遍历两个链表，不要忘了该指针也要向后走
    
    递归算法代码简洁，但时间效率比迭代低，由于其进行了大量的
    重复计算，若递归层次太深，还会导致程序崩溃，堆栈溢出等情况
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL)
       return l2;
    if(l2 == NULL)
        return l1;
    struct ListNode* pList1 = l1;   
    struct ListNode* pList2 = l2;
    struct ListNode* pList3 = NULL;
    
    if(pList1->val <= pList2->val)
    {
        pList3 = l1;
        pList1 = pList1->next;
    }
    else
    {
        pList3 = l2;
        pList2 = pList2->next;
    }
    
    struct ListNode *temp = pList3;
    while(pList1 != NULL && pList2 != NULL)
    {
        if(pList1->val <= pList2->val)
        {
            temp->next = pList1;
            pList1 = pList1->next;
        }
        else
        {
            temp->next = pList2;
            pList2 = pList2->next;
        }
        temp = temp->next;   // 坑，不能忘了temp也要向后走
    }
    if(pList1 == NULL)
    {
        temp->next = pList2;
    }
    if(pList2 == NULL)
    {
        temp->next = pList1;
    }
    return pList3;
}

// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//     if(l1 == NULL)
//         return l2;
//     if(l2 == NULL)
//         return l1;
    
//     struct ListNode* NewList = NULL;
//     if(l1->val <= l2->val)
//     {
//         NewList = l1;
//         NewList->next = mergeTwoLists(l1->next,l2);
//     }
//     else
//     {
//         NewList = l2;
//         NewList->next = mergeTwoLists(l1,l2->next);
//     }
//     return NewList;
// }