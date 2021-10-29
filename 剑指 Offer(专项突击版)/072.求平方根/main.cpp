// 求平方根

// 对于每一个mid
// 如果有mid*mid<=n：
//      if (mid+1)*(mid+1)>n, mid就是平方根
//      否则证明范围小了，l = mid+1
// 否则，r = mid - 1

// 注意：直接相乘会越界

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        if(x < 4)return 1;
        int l=1, r=x, mid;
        while(l<=r){
            mid = l + (r-l)/2;  // 为了避免(l+r)/2带来的越界
            if(mid <= x/mid){
                if(mid+1 > (x/(mid+1)))return mid;
                l = mid+1;
            }else r = mid-1;
        }
        return 0;
    }
};