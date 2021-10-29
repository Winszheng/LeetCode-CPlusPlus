#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
 
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l=1, r=piles.back(), mid;
        while(l<r){
            mid = (l+r)/2;
            int hour = 0;
            for(int i=0;i<piles.size();i++){
                hour += ceil(1.0*piles[i] / mid);    // 向上取整
            }
            if(hour <= h){
                // 速度太快
                r = mid;
            }else l=mid+1;
        }
        return l;
    }
};

int main(){
    vector<int> test1{3, 6, 7, 11};
    vector<int> test2{312884470};
    Solution s;
    // s.minEatingSpeed(test1, 8);
    s.minEatingSpeed(test2, 312884469);
}
