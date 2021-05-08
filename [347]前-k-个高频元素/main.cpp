#include "347.前-k-个高频元素.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Solution s;
    vector<int> nums{1, 2};
    
    vector<int> re = s.topKFrequent(nums, 2);
    for(int n : re)cout<<n<<" ";
    cout<<endl;
    return 0;
}
