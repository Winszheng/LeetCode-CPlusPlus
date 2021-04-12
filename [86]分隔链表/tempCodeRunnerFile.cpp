class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        if(!head->next)return head;
        ListNode *hh = new ListNode(0, head), *p = hh->next, *pre = hh->next, *temp = pre->next, *q;
        while(p->val != x){
            q = p;
            p = p->next;
            // cout<<"1";
        }
        while(temp && temp != p){   // 指针相同就是指向同一个地址么？
            if(temp->val < x){
                pre = temp;
                temp = temp->next;
                continue;
            }else{
                pre->next = temp->next;
                temp->next = p->next;
                p->next = temp;
                temp = pre->next;
            }
            // cout<<"2";
        }
        p = hh->next;
        while(p->val != x){
            q = p;
            p = p->next;
            // cout<<"1"<<endl;
        }
        pre = p, temp = p->next;
        // cout<<q->val<<","<<pre->val<<","<<temp->val<<endl;
        // return head;
        while(temp){
            if(temp->val > x){
                pre = temp;
                temp = temp->next;
                // cout<<"3";
                continue;
            }else{
                pre->next = temp->next;
                q->next = temp;
                temp->next = p;
                temp = pre->next;
                // cout<<"4";
            }
            
            
        }
        return hh->next;
    }
};