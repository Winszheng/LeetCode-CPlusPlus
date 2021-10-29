/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
// 本题考察的，本质上是构建单链表
// 结果最多会增加一位数字，但是进位可能会顺延很多位 —— 即，不断参与之后的计算，影响进位和结果
// 整体来说，应该依靠这样一个表来计算
// x(两位数字之和)  preCarry上个计算结果的进位 carry本次计算结果的进位
// 还有记得维持边界——考虑最后的carry是否为0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0), *hh = h;
        int carry = 0, remainder;
        while(l1 || l2){
            int x = 0;
            if(l1){
                x+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                x+=l2->val;
                l2 = l2->next;
            }
            int precarry = carry;
            carry = (x + precarry)/10;
            remainder = (x + precarry)%10;
            hh->next = new ListNode(remainder);
            hh = hh->next;
        }
        if(carry != 0){
            hh->next = new ListNode(carry);
            hh = hh->next;
        }
        hh->next = nullptr;
        return h->next;
    }
};
// @lc code=end

