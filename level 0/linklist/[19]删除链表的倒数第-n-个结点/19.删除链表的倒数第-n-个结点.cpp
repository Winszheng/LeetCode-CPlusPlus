/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
// 思路1：遍历一遍
// 1.先遍历一遍找到链表大小
// 2.第二遍遍历删除对应节点

// 思路2：只遍历一次——利用的是NULL到被删除节点的距离是固定的
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *hh = new ListNode(-1), *p, *q;
        hh->next = head;
        p = hh, q = hh;
        int i = 0;
        while(q){
            q = q->next;
            if(i<n+1)i++;
            else p = p->next;
        }
        p->next = p->next->next;
        return hh->next;
    }
};
// @lc code=end

