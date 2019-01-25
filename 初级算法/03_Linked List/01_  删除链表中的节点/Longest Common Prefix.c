/*
    算法思想：本题由于限定了链表至少有两个节点并且给出的节点
    不是尾节点，我们直接使用O(1)时间的删除结点算法，即让被删除
    节点的后继节点覆盖被删除节点，再将后继节点释放即可
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode* node) {
   
    struct ListNode*pDel = node;
    struct ListNode* pNext = pDel->next;
    
    pDel->val = pNext->val;
    pDel->next = pNext->next;
    
    free(pNext);
    
}