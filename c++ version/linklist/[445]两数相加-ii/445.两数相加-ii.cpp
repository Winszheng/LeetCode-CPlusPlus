/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
// 规范一下
// 空头结点h
// 空头结点下的第一个节点hh
// 如果有冲突就h1、h2，没毛病

// runtime 23.03 memory 5.35
// 如何优化？
// 1.我用了三个栈，但是第三个有点多余，可以直接倒着构建单链表
// 2.precarry在实际的使用中是多余的，每次取余和除法，都是用的上次进位和本次两位数的和，没毛病
// 那这道题的关键就在于倒着构建链表
// 优化之后：
// runtime 14.36 memory 60.93
// 还行
// 主要是这个写法比较不容易出错

#include <stack>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int a, b, cur, carry = 0;
        ListNode* ans = nullptr;
        while(!s1.empty() || !s2.empty() || carry!=0){
            a = s1.empty() ? 0 : s1.top();
            b = s2.empty() ? 0 : s2.top();
            if(!s1.empty())s1.pop();
            if(!s2.empty())s2.pop();
            cur = a+b+carry;
            carry = cur/10;
            cur %= 10;
            auto temp = new ListNode(cur);
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
};
// @lc code=end

