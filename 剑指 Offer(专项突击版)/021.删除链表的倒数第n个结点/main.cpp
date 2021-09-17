/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 经常会用一个假头结点作为辅助(避免链表只有一个节点的时候，需要做特殊处理)
// 双指针，一遍遍历出结果，因为区间的大小是固定的
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* hh = new ListNode(-1), *a, *b;
        hh->next = head;
        a = hh, b = hh;
        int i = 0;
        while(b){
            if(i<n+1){
                b=b->next;
                i++;
            }
            else{
                a = a->next;
                b = b->next;
            }
        }
        a->next = a->next->next;
        return hh->next;
    }
};