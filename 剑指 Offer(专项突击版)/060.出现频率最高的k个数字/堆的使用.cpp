#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    struct cmp{ // 这样得出的，是个大顶堆
        bool operator()(int a, int b){
            return a < b;
        }
    };
    void testHeap(vector<int>& nums){
        // 基本元素 元素的集合形式 比较方式
        priority_queue<int, vector<int>, cmp> q;
        for(int n : nums){
            q.push(n);
            cout<<q.top()<<" ";
        }
        cout<<endl;
    }
};

int main(){
    vector<int> nums{2, 7, 1, 4, 9};
    Solution s;
    s.testHeap(nums);
    // 2 7 7 7 9
}

