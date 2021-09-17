// ２.快慢指针　——　问题演变成追及问题

// 定义快指针步长为２，慢指针步长为１
// fast走的步长一共为f， slow走的步长一共为s，环外节点数为a，环内节点数为b
// 那么，相遇时有这样的关系成立：
// f = 2s
// s = a+nb(n表绕圈数)
// ==> s = nb

// 而每当指针走到环的入口时，都有下式成立：
// 步长 = a + nb(n∈N，表绕圈数)
// 那么，s只要再走a步就能到入口节点
// 由于a的大小未知，让一个指针从head节点同时出发，相遇点就在入口节点

// 空想很麻烦，画图很简单
// 时间效率很高，但空间效率依然比较低 —— 虽然没有开辟内存空间
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(1){
            if(!fast || !fast->next)return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)break;  // 链表有环
        }
        // slow再走a步能到入口节点
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};