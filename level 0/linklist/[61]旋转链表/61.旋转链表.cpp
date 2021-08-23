/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
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

// 注意提示里的k范围比节点数目大很多
// 所以需要取余
// 否则一个个循环起来会很慢

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *hh = new ListNode(-1), *p, *q, *t;
        hh->next = head;
        p = hh;
        q = hh;
        t = head;
        if(!head || !head->next)return head;

        int n=0;
        while(t){
            t = t->next;
            n++;
        }
        k %= n;
        int i = 0;
        while(q->next){
            if(i<k)i++;
            else p = p->next;

            q = q->next;
        }
        q->next = hh->next;
        hh->next = p->next;
        p->next = nullptr;
        return hh->next;
    }
};
// @lc code=end

