// 考察链表的插入操作——头插法
// 相当于一直进行3个指针的操作，直到没有可以操作的指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return NULL;
        ListNode* hh = new ListNode(-1), *b;
        hh->next = head, b = head->next;
        while(b){
            head->next = b->next;
            b->next = hh->next;
            hh->next = b;
            b = head->next;
        }
        return hh->next;
    }
};