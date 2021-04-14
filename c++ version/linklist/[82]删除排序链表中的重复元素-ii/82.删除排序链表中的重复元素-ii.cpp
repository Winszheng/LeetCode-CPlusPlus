/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
// 一看就是可以用虚拟头结点规避部分操作的题目
// 这道题好难理解，靠

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // hh:虚拟头结点 tail:有效链表末尾节点 temp:需要删除的哑节点 
        // 通过移动head节点完成删除升序链表中的重复元素
        ListNode *hh = new ListNode(0), *tail, *temp;
        hh->next = head, tail = hh;
        while(head){
            // 当val不重复时
            if(!head->next || head->val != head->next->val){
                tail = head;
                head = head->next;
                continue;
            }
            // 当val重复时
            // 在这个循环中，head->next依存于head，head是必然不空的
            // 所以要检验head->next是否为空
            // 如果在比较过程中因为空出去，那么最后一个元素也要删掉==
            while(head->next && head->val == head->next->val){
                temp = head;
                tail->next = head->next;
                delete temp;
                head = tail->next;
            }
            temp = tail->next;
            tail->next = temp->next;
            delete temp;
            head = tail->next;
        }
        return hh->next;
        
    }
};
// @lc code=end

