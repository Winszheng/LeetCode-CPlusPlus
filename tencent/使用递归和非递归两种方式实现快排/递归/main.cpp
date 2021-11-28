#include <vector>
#include <iostream>
using namespace std;
// 递归实现快排

// 对撞指针+二分思想
// 右指针：如果元素大于等于基准，下一个
// 左指针：如果元素小于等于基准，下一个
// 最终右指针会撞上左指针，因为是右指针撞上左指针，所以这个值一定小于基准值，因此可以直接交换
// 事实上在上述的对撞过程中，就包含了对仅有两个元素时的处理，而1个元素显然不需要处理
// 而确定下一个递归范围时，有可能导致范围内只有一个元素甚至左侧比右侧大
// 因此递归的结束条件就是左侧大于等于右侧

// trick: 需要随机选取基准并swap到左侧，否则不论是递归还是迭代都会超时
// reason: 为了规避基准过大过小的情况

// ac: 时空效率很ok
class Solution {
public:
    void quick(vector<int>& nums, int l, int r){
        if(l >= r)return;                       // 递归的结束条件
        int i = l, j = r;
        int t = rand() % (r-l+1) + l;           // 随机选取基准，规避过大or过小的基准
        swap(nums[l], nums[t]);
        int flag = nums[i];
        while(i < j){
            while(nums[j]>=flag && i<j)j--;     // 要么找到小于基准的值 要么撞到左指针
            while(nums[i]<=flag && i<j)i++;     // 要么找到大于基准的值 要么避免被右指针撞到之后依然继续跑
            if(i < j)swap(nums[i], nums[j]);    // 两边都找到了合法值
        }

        nums[l] = nums[i], nums[i] = flag;      // 出循环要调整基准值
        
        quick(nums, l, i-1);    // 尝试递归进入下一层
        quick(nums, i+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() < 2)return nums;
        quick(nums, 0, nums.size()-1);
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