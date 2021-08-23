/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */

// @lc code=start

// 1.蓄水池算法的核心:
// 对于1概率是1，
// 对于2概率是1/2
// 对于3就是概率1/3
// 一次类推直到1/n为止

// 2.rand()的范围，0到最大值

class Solution {
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int k = 2;
        ListNode *cur = head->next;
        int re = head->val;
        while(cur){
            if(rand()%k == 0){
                re = cur->val;
            }
            cur = cur->next;
            k++;
        }
        return re;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

