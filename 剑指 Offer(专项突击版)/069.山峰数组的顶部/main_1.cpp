#include <vector>
#include <iostream>
using namespace std;
// 寻峰问题, 二分法
// 如果mid的左右比他低，return
// 如果mid处于上升段，找右
// 如果mid处于下降段，找左

// 因为题目保证有解，所以不用考虑边界
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1, r=arr.size()-2, mid;
        while(l <= r){
            mid = (l+r)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
            if(arr[mid]>arr[mid-1])l = mid+1;
            else r = mid-1;
        }
        return mid;
    }
};

int main(){
    Solution s;
    vector<int> temp{3,5,3,2,0};
    cout<<s.peakIndexInMountainArray(temp)<<endl;
}