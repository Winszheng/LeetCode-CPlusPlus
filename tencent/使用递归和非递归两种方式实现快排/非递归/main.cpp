#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 非递归实现快排
// 事实上和递归是一个做法，区别在于，把递归区间记忆化，从而减少栈的深度，避免爆栈
// 基准需要随机化，否则当选取基准太大or太小，会超时
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() < 2)return nums;
        queue<int> left, right; left.push(0), right.push(nums.size()-1);
        while(!left.empty()){    // 当队列非空，即存在区间需要校正基准
            int l = left.front(), r = right.front(); left.pop(), right.pop();
            if(l >= r)continue;
            int t = rand() % (r-l+1) + l;   // 用最右边界进行设想
            
            int i = l, j = r;
            swap(nums[l], nums[t]);
            int flag = nums[l];
            // 开始校准
            while(i < j){
                while(nums[j]>=flag && i<j)j--;
                while(nums[i]<=flag && i<j)i++;
                if(i<j)swap(nums[i], nums[j]);
            }
            nums[l] = nums[i], nums[i] = flag;
            left.push(l), right.push(i-1);
            left.push(i+1), right.push(r);
        }
        return nums;
    }
};

int main(){
    vector<int> test1{5, 2, 3, 1};
    Solution s; 
    vector<int> re1 = s.sortArray(test1); 
    for(int n : re1)cout<< n <<" ";
    cout<<endl;
}