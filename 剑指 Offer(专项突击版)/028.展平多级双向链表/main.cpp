// 展平链表 - 递归
// 因为递归深度只有三层，所以时空效率非常高
class Solution {
public:
    Node* flatten(Node* head) {
        Node *a = head;
        while(a){
            if(!a->child){
                a = a->next;
                continue;
            }
            Node* t = flatten(a->child);a->child = NULL;
            Node* tail = t;
            while(tail->next)tail = tail->next;
            tail->next = a->next;
            if(tail->next)tail->next->prev = tail;  // 这个条件判断是写对的关键，因为a的next可能是NULL
            a->next = t; t->prev = a;
            a = tail->next;
        }
        return head;
    }
};
