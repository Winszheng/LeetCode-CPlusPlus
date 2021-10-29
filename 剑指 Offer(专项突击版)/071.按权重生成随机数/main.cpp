#include <vector>
#include <stdlib.h>
using namespace std;
// 按权重获取随机数, 根据权重数组构造累计权重数组，然后二分查找
// 找到一个元素，让随机数的值落在它所表达的区间当中

// 注意判断的时候，等于也算落在了区间，那么生成随机值的时候，要+1
class Solution {
public:
    vector<int> re;
    Solution(vector<int>& w) {
        int pre = 0;
        for(auto n : w){
            re.push_back(pre+n);
            pre = *(re.end()-1);
        }
    }
    
    int pickIndex() {
        int l=0, r=re.size()-1, mid;
        int ran = rand() % re[r] + 1;   // 是边界的问题
        while(l <= r){
            mid = (l+r)/2;
            if(ran <= re[mid]){
                if(mid==0 || ran>re[mid-1])return mid;
                r = mid-1;
            }else l = mid+1;
        }
        return -1;
    }
};
