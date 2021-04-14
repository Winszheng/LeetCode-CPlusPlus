/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
// 经典的虚拟头结点操作
// 很好写
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *hh = new ListNode(0), *cur;
        hh->next = head, cur = hh;
        while(cur->next){
            if(cur->next->val == val){
                ListNode* temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }else{
                cur = cur->next;
            }
        }
        return hh->next;
    }
};
// @lc code=end

