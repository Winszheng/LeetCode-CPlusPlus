#include <iostream>
#include <vector>
using namespace std;

// 构造一棵层高为32的前缀树(层高固定)
// re*2 + 1
// re*2
struct node{
    vector<node*> child; 
    node(){
        child = vector<node*>(2, NULL);
    }
};

class Solution {
public:
    int re = 0;
    node *hh = new node();
    void insert(int x){
        node *tail = hh;
        for(int i=31; i>=0;i--){
            int n = (x >> i) & 1;   // 获取每一位的值
            if(!tail->child[n]){
                tail->child[n] = new node();
            }
            tail = tail->child[n]; 
        }
    }
    void search(int x){
        int tmp = 0;
        node *tail = hh;
        for(int i=31; i>=0; i--){
            int n = (x >> i) & 1;
            if(tail->child[1-n]){
                tmp = (tmp << 1) + 1; tail = tail->child[1-n];
            }else{
                tmp = tmp << 1; tail = tail->child[n];
            }
        }
        re = max(re, tmp);
    }
    int findMaximumXOR(vector<int>& nums) {
        for(int x : nums)insert(x); // 构造前缀树
        for(int x : nums)search(x); // 搜索最优解
        return re;
    }
};
// 0 1
// 0 0 1
int main(){
    Solution s;
    vector<int> test1{3, 10, 5, 25, 2, 8};
    vector<int> test2{0};
    vector<int> test3{2, 4};
    cout<<s.findMaximumXOR(test1)<<endl;
}