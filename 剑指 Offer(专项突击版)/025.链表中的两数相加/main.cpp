#include <stack>
using namespace std;

// 考察插入节点，头插法

// 链表中的两数相加，头结点存最高位
// 方法1: 先反转链表，再进行正常的相加，最后把结果反转 —— 写个reverse函数反而比用stack更好更省事
// 方法2: 为了省事用了stack，但其实没有省事多少

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
        ListNode *hh = new ListNode(-1), *b = hh->next;
        
        int c = 0;
        while(!s1.empty() ||  !s2.empty()){ // 这样就不用写三遍
            int t = c;
            if(!s1.empty()){
                t += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                t += s2.top();
                s2.pop();
            }
            c = t/10;
            t %= 10;
            ListNode *tmp = new ListNode(t);
            tmp->next = b;
            hh->next = tmp;
            b = hh->next;
        }
        if(c!=0){
            ListNode *tmp = new ListNode(c);
            tmp->next = b;
            hh->next = tmp;
            b = hh->next;
        }
        return hh->next;
    }
};  