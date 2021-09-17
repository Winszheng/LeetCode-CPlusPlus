#include <iostream>
using namespace std;
// 1.首先通过快慢指针找到中间节点(偶数个节点时，是中间偏左节点)
// 2.反转后半部分链表，反转后把慢指针的指向赋空，避免操作结果有环
// 3.拼接链表

// 过了，而且，时空效率都还不错
// 空间效率1
// 时间效率n
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 头插法反转链表
    ListNode* reverse(ListNode* head){
        ListNode* hh = new ListNode(-1), *b;
        hh->next = head;
        b = head->next; // b表征要操作的节点
        while(b){
            head->next = b->next;   // 先把要操作的节点隔离开，同时保证链表连贯性
            b->next = hh->next;
            hh->next = b;
            b = head->next;
        }
        return hh->next;
    }
public:
    void reorderList(ListNode* head) {
        if(!head->next)return;  // 如果只有一个节点，那么不用操作
        ListNode *f=head, *s=head, *a, *b, *tmp;
        while(f->next && f->next->next){
            f = f->next->next;
            s = s->next;
        }   
        b = reverse(s->next);   // 反转链表并把头结点赋值给t，t用来标记当前操作的节点(第二条链表)
        s->next = NULL; // 分割两段链表，避免成环
        a = head;   // hh用来标记当前要操作的节点(第一条链表)

        while(b){
            tmp = b->next;
            b->next = a->next;
            a->next = b;
            a = b->next;
            b = tmp;
        }
    }
};

int main(){
    ListNode *n1 = new ListNode(1), *n2, *n3, *n4;
    n2 = new ListNode(2), n3 = new ListNode(3), n4 = new ListNode(4);
    n1->next = n2, n2->next = n3, n3->next = n4;
    Solution s;
    s.reorderList(n1);
}