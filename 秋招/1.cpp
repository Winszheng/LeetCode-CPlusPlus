#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 属于签到题
// 不断修改值
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a ListNode类vector 指向这些数链的开头
     * @return ListNode类
     */
    ListNode* solve(vector<ListNode*>& a) {
        ListNode* head = new ListNode(0); ListNode *tail=head;
        int n = a.size();
        while(1){
            int empty = 0;
            for(int i=0; i<n; i++){
                if(a[i]){
                    tail->next = a[i];a[i]=a[i]->next;
                    tail = tail->next;
                }else{
                    empty++;
                }
            }
            if(empty == n)break;
        }
        return head->next;
    }
};

int main(){
    vector<ListNode*> a;
    ListNode* h1 = new ListNode(1); h1->next = new ListNode(2);h1->next->next = new ListNode(3);
    ListNode* h2 = new ListNode(4); h1->next = new ListNode(5);
    a.push_back(h1);a.push_back(h2);
    Solution s;
    s.solve(a);
}