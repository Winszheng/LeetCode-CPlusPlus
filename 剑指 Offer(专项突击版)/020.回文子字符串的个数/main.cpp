#include <string>
#include <iostream>
using namespace std;

// 以每个字符自己为中心进行比较
// 可以是奇数中心，也可以是偶数中心

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), re=0;
        for(int i=0;i<n;i++){
            int l=i, r=i;
            while(l>=0 && r<n && s[l] == s[r]){
                re++, l--, r++;
            }
            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                re++, l--, r++;
            }
        }
        return re;
    }
};

int main(){
    Solution s;
    cout<<s.countSubstrings("aaa")<<endl;
}