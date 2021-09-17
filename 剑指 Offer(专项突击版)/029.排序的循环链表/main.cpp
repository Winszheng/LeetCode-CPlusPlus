// 本题会有重复值
// 如果顺着题目的表面要求去做分类讨论，会很麻烦
// 比较好的做法是一边循环，标记真正的头结点(最小值)、尾节点(最大值)
// 考虑到可能会有重复值，头节点只有遇到 真·小值才能动、尾节点只要大于等于就能动
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head){
            head = new Node(insertVal); head->next = head;
            return head;
        }
        Node *t = new Node(insertVal);
        if(!head->next){
            head->next = t; t->next = head;
            return head;
        }
        // 找到真正的头结点、尾节点
        Node *hh = head, *tail = head, *tmp = head->next;
        while(tmp != head){ // 避免死循环走不出来
            if(tmp->val < hh->val)hh = tmp;
            if(tmp->val >= tail->val)tail = tmp;    // 以此避免头尾的问题
            tmp = tmp->next;
        }
        // 至此，hh指向的节点是最小的，即，真正的头结点
        if(insertVal < hh->val || insertVal > tail->val){
            t->next = hh;
            tail->next = t;
            return head;
        }
        tmp = hh->next;
        while(1){
            if(hh->val<= t->val && t->val<=tmp->val){
                t->next = tmp;
                hh->next = t;
                return head;
            }
            hh = tmp;
            tmp = tmp->next;
        }
        return head;
    }
};