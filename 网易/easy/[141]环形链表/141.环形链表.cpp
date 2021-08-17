/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
#include <iostream>
using namespace std;

// 用stl，省事很多

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *hh = head;
        unordered_set<ListNode*> temp;
        while(hh){
            if(temp.count(hh))return true;
            temp.insert(hh);
            hh = hh->next;
        }
        return false;
    }
};

// @lc code=end

