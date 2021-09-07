#include <vector>
#include <iostream>
using namespace std;

// 1.位运算
// 因为int由32位0或1组成
// 把所有数字同一位上的数字相加，再对3取余，由于所有数字不是出现1遍就是出现3遍，所以取余的结果就是re对应位数的值
// 通常用左移/右移来表征二进制数的第几位

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int re = 0;
        for(int i=0; i<32; i++){
            int temp = 0;
            for(int n : nums){
                temp += (n >> (31-i)) & 1;  //  经典操作：获取32位int从左往右的每一位
            }
            re = (re << 1) + temp%3;
        }
        return re;
    }
};

int main(){
    Solution s; 
    vector<int> re({2,3,2,2});
    // cout<<s.singleNumber(re)<<endl;
    int a = 8;
    cout<< (a >> 1)<<endl;
}


// 这货动的是头是尾，真的有关系吗？有，动头比较省事。
// 不见得吧...
