/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
// 搞半天是我理解错了题意，啊！！！
// 官方题解写得挺好
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode *small = new ListNode(0), *large = new ListNode(0);
       ListNode *sh = small, *lh = large;
       while(head){
           if(head->val < x){
               small->next = head;
               small = small->next;
           }else{
               large->next = head;
               large = large->next;
           }
           head = head->next;
       }
       small->next = lh->next;
       large->next = nullptr;
       return sh->next;
    }
};
// @lc code=end

