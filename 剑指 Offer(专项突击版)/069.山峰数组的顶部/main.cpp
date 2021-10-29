#include <vector>
using namespace std;

// 整个数组先递增再递减，求顶部
// 直观做法是O(n)级别的
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        while(arr[i+1] > arr[i])i++;
        return i;
    }
};