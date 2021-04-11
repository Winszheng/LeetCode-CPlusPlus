#include "92.反转链表-ii.cpp"
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

ListNode* createLinkedList(int arr[], int n){]
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