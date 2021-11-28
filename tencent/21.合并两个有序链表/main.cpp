// 按序合并两个有序链表
// 简单操作
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 假头结点帮助工作
        ListNode *hh = new ListNode(-1), *tail = hh;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1; l1 = l1->next; tail = tail->next;
            }else {
                tail->next = l2; l2 = l2->next; tail = tail->next;
            }
        }
        if(l1)tail->next = l1;
        if(l2)tail->next = l2;
        return hh->next;
    }
};