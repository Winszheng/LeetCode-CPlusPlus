// 1.哈希表-存一条链表、查一条链表，O(n)空间 O(n)时间
// 2.递归 - 可能爆栈
// 3.双指针，先各自遍历一遍，求两条链表的长度，根据差值去找交汇点
//   空间效率1，时间效率n
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ta = headA, *tb = headB;
        int n=0, m=0;
        while(ta){
            ta = ta->next;
            n++;
        }
        while(tb){
            tb = tb->next;
            m++;
        }
        ta = headA, tb = headB;
        if(n>m){
            for(int i=0;i<n-m;i++)ta = ta->next;
        }else{
            for(int i=0;i<m-n;i++)tb = tb->next;
        }
        while(ta != tb){
            ta = ta->next;
            tb = tb->next;
        }
        return ta;
    }
};

