#include <string>
#include <iostream>
#include <vector>
using namespace std;
// 字符 数字 符号 空格的范围是0-127

// 滑动窗口，如果没有重复字符，就一直扩展右边
// 如果遇到重复字符，就收束左边，直到把与右端相同的字符排除窗外
// 滑动窗口要划过整个区

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l=0, r=-1, n=s.size(), re=0;
       vector<int> win(128);
       while(l < n){
           if(r+1<n && win[s[r+1]]==0){
               win[s[r+1]]=1;
               r++;
           }else{
               win[s[l]] = 0; 
               l++;
           }
           re = max(re, r-l+1);
       }
       return re;
    }
};

int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("--")<<endl;
}