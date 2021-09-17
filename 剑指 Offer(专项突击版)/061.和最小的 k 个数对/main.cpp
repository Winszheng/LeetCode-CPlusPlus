#include <vector>
#include <queue>
using namespace std;
// 思路：二重循环，构建大小k的小顶堆
// 10的9次方 相加 相减 不需要担心溢出

// 求最小的k个值，维持一个大顶堆，堆满时，小则替换，最后留在堆里的会是最小的k个值
// 时空效率不错
class Solution {
public:
    struct cmp{
        bool operator() (pair<int, int> a, pair<int, int> b){
            // 构造大顶堆
            return (a.first + a.second) < (b.first + b.second);
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for(int n : nums1){
            for(int m : nums2){
                if(q.size() < k)q.push(make_pair(n, m));
                else if((q.top().first+q.top().second) > n+m){
                    q.pop();q.push(make_pair(n, m));
                }
            }
        }
        vector<vector<int>> re;
        while(!q.empty()){
            auto o = q.top(); q.pop();
            re.push_back({o.first, o.second});
        }
        return re;
    }
};