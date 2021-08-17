/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include <iostream>
using namespace std;
// @lc code=start

// struct ListNode{
//     int val;
//     ListNode *next;
//     ListNode(): val(0), next(nullptr){}
//     ListNode(int x): val(x), next(nullptr){}
//     ListNode(int x, ListNode *next): val(x), next(next){}
// };

// 思路：尾插法构造链表，和之前写的一样，注意要先求的余数再改变进位值
// x = (a+b+c)%10
// c = (a+b+b)/10
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* hh = new ListNode(), *temp = hh;
        int c = 0;
        while(l1 && l2){
            int x = (l1->val + l2->val + c)%10;
            temp->next = new ListNode(x);
            c =  (l1->val + l2->val + c) / 10;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int x = (l1->val + c) %10;
            temp->next = new ListNode(x);
            c = (l1->val + c) / 10;
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2){
            int x = (l2->val + c) %10;
            temp->next = new ListNode(x);
            c = (l2->val + c) / 10;
            temp = temp->next;
            l2 = l2->next;
        }
        if(c == 1){
            temp->next = new ListNode(1);
        }
        return hh->next;
    }
};

// int main(){
//     ListNode* hh;
//     hh->val = 10;   // segmentation fault (core dumped)
//     cout<<hh->val<<endl;
// }
// @lc code=end

