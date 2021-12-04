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
// 删除升序链表中的所有重复元素
// 因为重复的元素可能有多个，所以不要因为删除了重复元素，就修改source元素的指向
// 当双指针指向不一样时，才表示当前元素探测完毕，可以检测下一个元素

// 边界老选错
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        auto cur = head, next = cur->next;
        while(next){    // 当next元素存在时，才有检测的意义
            if(cur->val == next->val)cur->next = next->next;
            else cur = next;
            next = cur->next;
        }
        return head;
    }
};