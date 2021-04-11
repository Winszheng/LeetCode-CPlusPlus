/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// 链表题，注意不要对空指针做引用
// 本质上说，这道题的next是依存于cur，只有cur非空的时候，next才有意义。
// 时间复杂度O(n)
// 空间复杂度，由于开了三个指针，所以是O(1)

// 反转整个链表，只需要修改指向
// 没什么必要用头插法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // member access within null pointer of type 'ListNode'
        // *next = head->next——如果传空链表，会表示试图引用空指针 
        ListNode *pre = nullptr, *cur = head, *next;   
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;

    }
};
// @lc code=end

