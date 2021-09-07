#include "347_1.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Solution s;
    vector<int> nums{1};
    
    vector<int> re = s.topKFrequent(nums, 1);
    for(int n : re)cout<<n<<" ";
    cout<<endl;
    return 0;
}
