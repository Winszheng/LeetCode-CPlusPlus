/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start

// Definition for singly-linked list.
//  struct ListNode {
//     int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)return head;
        ListNode* hh = new ListNode(-1, head), *hhh=hh, *p, *temp;
        for(int i=0;i<left-1;i++)hhh=hhh->next;
        p = hhh->next;
        for(int i=0;i<right-left;i++){
            temp = p->next;
            p->next = temp->next;
            temp->next = hhh->next;
            hhh->next = temp;
        }
        return hh->next;
    }
};
// 头插法，经典而且简单==
// 1.先给原链表添加一个假头结点hh，这是为了避免处理边界的麻烦
// 2.然后找到反转序列的前一个节点，作为实际操作的“假头结点”——下次改叫pp吧...
//      - 反转整个链表的时候，pp和hh虽然一开始指向同一个地方，相当于合体了
// 3.反转链表的第一个节点是锚点
// 4.操作right-left次，也就是只修改中间指针的指向
// 5.返回假头结点的next就行了
// @lc code=end

