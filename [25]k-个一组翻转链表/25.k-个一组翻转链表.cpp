/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
// first submission： 19/21
// 我觉得我的思路比题解要好...主要是清晰好懂


class Solution {
    void reverse(ListNode *hh, int n){
        ListNode *head = hh->next, *temp = head->next;
        int i = 1;
        while(i<n){
            i++;
            head->next = temp->next;
            temp->next = hh->next;
            hh->next = temp;

            temp = head->next;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *hh = new ListNode(0), *tail, *pre;
        hh->next = head;
        int n = 0;        
        while(1){
            tail = hh;
            for(int j=0; j<n*k;j++)tail = tail->next;
            n++;

            pre = tail;
            for(int i = 0; i<k; i++){
                if(tail->next)tail = tail->next;
                else return hh->next;
            }
            reverse(pre, k);
        }
        return hh->next;
    }
};
// @lc code=end

