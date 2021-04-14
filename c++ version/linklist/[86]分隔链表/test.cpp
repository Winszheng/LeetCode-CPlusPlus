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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0), *hh = h;
        int carry = 0, remainder;
        while(l1 || l2){
            int x = 0;
            if(l1){
                x+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                x+=l2->val;
                l2 = l2->next;
            }
            int precarry = carry;
            carry = (x + precarry)/10;
            remainder = (x + precarry)%10;
            hh->next = new ListNode(remainder);
            hh = hh->next;
        }
        if(carry != 0){
            hh->next = new ListNode(carry);
        }
        hh->next = nullptr;
        return h->next;
    }
};

// 又是不小心把pre->next写成pre
// 不要用“修改pre的指向”，用“修改pre的指针”，这样比较明确
int main(){
    int arr1[] = {9,9,9,9,9,9,9};
    int arr2[] = {9,9,9,9};
    ListNode* l1 = createLinkedList(arr1, 7);
    ListNode* l2 = createLinkedList(arr2, 4);
    Solution s;
    ListNode* l3 = s.addTwoNumbers(l1, l2);
    printLinkedList(l3);
    deleteLinkedList(l3);
}