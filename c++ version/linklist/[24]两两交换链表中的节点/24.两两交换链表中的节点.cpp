/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
// 本质上就是先删除再插入
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *hh = new ListNode(-1), *tail, *temp;
        hh->next = head;
        tail = hh;
        while(tail->next && tail->next->next){
            temp = tail->next->next;
            tail->next->next = temp->next;
            temp->next = tail->next;
            tail->next = temp;

            tail = tail->next->next;
        }
        return hh->next;
    }
};
// @lc code=end

