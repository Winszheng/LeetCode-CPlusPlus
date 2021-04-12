#include <iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(int arr[], int n){
    if(n==0)return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i=1; i<n; i++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    return head;
}

void printLinkedList(ListNode* head){
    ListNode* curNode = head;
    while(curNode){
        cout<<curNode->val<<"->";
        curNode=curNode->next;
    }
    cout<<"NULL"<<endl;
}

void deleteLinkedList(ListNode* head){
    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head; // 链表为空
        if(!head->next)return head;
        ListNode *hh = new ListNode(0, head), *hhh = hh->next, *pre = hhh, *temp;
        while(pre && pre->val != x)pre = pre->next;
        temp = pre->next;
        
        // int i = 0;
        while(temp){
            // i++;
            if(temp->val >= x){
                pre = temp;
                temp = temp->next;
                
                continue;
            }
            // if(i>10)return hhh;
            // return head;
            // printLinkedList(head);
            // cout<<pre->val<<","<<temp->val<<endl;
            pre->next = temp->next;
            // // 关于拿走一个节点和插入一个节点
            // // 1.拿走一个节点
            // // 拿走a->b->c中的b节点
            // // 要先动a的指向，之后就可以操作b的指向
            // // 2.插入一个节点
            // // 把c节点插入a->b的时候
            // // 要“先右后左”，先动c的next再动d的next，否则a就直接和b“失联”了
            // // 总结：
            // // 拿走节点要先动左边的节点；插入节点要先动右边的节点，这里的左右指的是元素的相对位置
            temp->next = hhh->next;
            hhh->next = temp;

            temp = pre->next;
            
        }
        return hhh;
    }
};

// 又是不小心把pre->next写成pre
// 不要用“修改pre的指向”，用“修改pre的指针”，这样比较明确
int main(){
    int arr[] = {1,2};
    ListNode* head = createLinkedList(arr, 6);
    Solution s;
    s.partition(head, 3);
    printLinkedList(head);
    deleteLinkedList(head);
}