/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
// 思路对了很好做
// 要点：
// 插入排序，是把数组分为已排序和未排序数组，每次都把操作的待排序元素放到已排序的适当位置
// 即特点为：前边的队列是有序的！
// 一如既往，*hh、*tail、*temp
// 当tail的元素<=temp的元素，无需排序，直接操作下一个
// 否则，temp节点一定可以插在前面
// 为了规避找到temp应该待的地方，需要有左右两个节点这种麻烦事
// 可以只操作左节点pre
// 确实是中等题的水平，是我之前想得太麻烦
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *hh = new ListNode(-1), *tail, *temp, *pre;
        hh->next = head;
        tail = head;
        temp = tail->next;
        while(temp){
            if(temp->val >= tail->val){
                tail = tail->next;
            }else{
                pre = hh;
                while(pre->next->val <= temp->val)pre = pre->next;

                tail->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            temp = tail->next;
        }
        return hh->next;
    }
};
// @lc code=end

