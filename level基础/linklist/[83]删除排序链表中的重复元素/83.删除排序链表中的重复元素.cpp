/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
// 问题1
// C++之父认为这样写是不好的，提倡直接写(p)或(!p)的形式
// 至于实际上...
// 其他写法，在不同平台上结果可能不一样
// 所以我个人喜欢用用(p)和(!p)这种形式

// 问题2：注意，leetcode的链表题可能会传空链表。没留意到的话会报堆溢出(引用空指针)

// 问题3：leetcode的题目中，删除的节点是否delete都能过(绝了)
// 而且是否delete，时空结果是成负相关...所以我决定麻烦的时候delete

// 问题4：我老是把p和p->next混用

// 虽然有人用了增加假头结点的方法做，但我觉得没有必要
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        auto p = head, q = p->next;
        while(q){
            if(p->val == q->val){
                p->next = q->next;
                delete q;
                q = p->next;
            }else{
                p = q;
                q = q->next;
            }

        }
        return head;
    }
};
// @lc code=end

