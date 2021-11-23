#include <vector>
using namespace std;
// 1.f[i] 指爬到第i级别可以有的方法
// 2.f[i] = f[i-1] +f[i-2]
// 也可以滚动变量，实际要操作的，只有3个变量
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2)return n;
        int s1=1, s2=2, s3;
        for(int i=3; i<=n; i++){
            s3 = s1+s2;
            s1 = s2;
            s2 = s3;
        } 
        return s3;
    }
};
