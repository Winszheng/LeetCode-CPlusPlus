/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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

// 初始办法：顺序合并，虽然是hard题，但是写起来很快，160ms也还可以

// 133/133 cases passed (160 ms)
// Your runtime beats 28.5 % of cpp submissions
// Your memory usage beats 43.67 % of cpp submissions (13.1 MB)

// 感觉优先队列写起来比较麻烦，不探索了
class Solution {
    ListNode* merge(ListNode *a, ListNode *b){
        if(!a || !b)return a ? a : b;
        ListNode *head = new ListNode(-1), *tail = head;
        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *re = nullptr; // 局部变量的默认初始化是不可信的
        for(auto node : lists)re = merge(re, node);
        return re;        
    }
};
// @lc code=end

