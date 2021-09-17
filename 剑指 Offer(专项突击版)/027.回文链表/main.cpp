// 判断是否回文链表 O(n)时间，O(1)空间
// 1.通过快慢指针获取中间偏左节点
// 2.反转后半段链表，然后直接比较

// 更省事的做法是用vector存储数据再比较，但这会开辟不必要的内存空间
class Solution {
    ListNode* reverse(ListNode* head){
        if(!head)return NULL;
        ListNode *hh = new ListNode(-1), *b = head->next;
        hh->next = head;    
        // ListNode *hh = new ListNode(-1), hh->next = head; 这是错误的！编译器会认为你同时定义hh为指针和非指针
        while(b){
            head->next = b->next;
            b->next = hh->next;
            hh->next = b;
            b = head->next;
        }
        return hh->next;

    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next){
            return true;
        }
        ListNode *f=head, *s=head, *a=head, *b;
        while(f->next && f->next->next){
            f = f->next->next;
            s = s->next;
        }
        b = reverse(s->next);s->next = NULL;
        while(b){
            if(a->val != b->val)return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};