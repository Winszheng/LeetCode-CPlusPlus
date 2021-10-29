/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
// 这道题本质上和中等题分隔链表是一样的
// 做法完全通用
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0), *even = new ListNode(0);
        ListNode *oddhead = odd, *evenhead = even;
        int i = 0;
        while(head){
            i++;
            if(i%2 == 1){
                odd->next = head;
                odd = odd->next;
            }else{
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }
        odd->next = evenhead->next;
        even->next = nullptr;
        return oddhead->next;
    }
};
// @lc code=end

