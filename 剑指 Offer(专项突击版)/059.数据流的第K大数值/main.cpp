#include <queue>
using namespace std;

// 维持一个k大小的最小堆，那么堆顶始终是第k大的元素
// 考察c++中最小堆的使用

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> re;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n : nums){
            if(re.size() < k)re.push(n);
            else{
                if(re.top() < n){
                    re.pop();
                    re.push(n);
                }
            }
        }
    }
    
    int add(int val) {
        if(re.size() < k)re.push(val);
        else if(val > re.top()){
            re.pop();
            re.push(val);
        }
        return re.top();
    }
};
