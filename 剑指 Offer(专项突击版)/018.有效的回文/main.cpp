#include <string>
#include <iostream>
using namespace std;

// 判断是否回文串，只考虑字母和数字，忽略大小写


class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(char c: s){
            if(isalnum(c))ss += tolower(c);
        }
        int l=0, r=ss.size()-1;
        while(l<r){
            if(ss[l] != ss[r])return false;
            l++,r--;
        }
        return true;
    }
};

