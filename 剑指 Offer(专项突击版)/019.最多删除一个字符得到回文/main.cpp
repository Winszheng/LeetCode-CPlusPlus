#include <string>
#include <iostream>
using namespace std;

// 因为只要删除一个字符，所以尝试一下就可以了
class Solution {
public:
    bool resolve(string& s, int l, int r){
        while(l<r){
            if(s[l] != s[r])return false;
            l++, r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n =s.size();
        int l=0, r=n-1;
        while(l<r){
            if(s[l] == s[r]){
                l++, r--;
            }else{
                return resolve(s, l+1, r) || resolve(s, l, r-1);
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.validPalindrome("aba")<<endl;
}