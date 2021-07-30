/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// 思路1：暴力解法，超时
// 思路2：按找回文子串数量的思路，每个字符为中心找奇/偶长度回文串，
//       比较得到以s[0]为左边界的最长回文子串，测例全过但超时
// 思路3：改变找最长回文子串的做法，用reverse函数反转子串再比较，最后一个测例超时过不了
// 思路4：kmp
// 1.不回退主字符串，只回退pattern
// 2.每次回退pattern，都通过不断寻找次大匹配的方式(j = pmt[j-1])，以谋求回退最小的步长
// 3.关键在于求pmt数组(next数组相当于pmt右移1位，最左为了省事默认-1，用不用是个人习惯)
//  i表主字符串当前探测字符
//  j表pattern当前探测字符
//  pmt[i]表字符串[0, i]的最长前后缀匹配(指真前后缀，否则无意义)

// 落实到本题，通过把字符串反转拼接，找pmt数组，然后抛弃重复的部分即可

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() < 2)return s;

        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + '#' + rev;
        int n = temp.size();
        vector<int> pmt(n, 0);
        for(int j=0, i=1; i<n;){
            if(j==0 && temp[i] != temp[j]){ // j=0且失配 
                pmt[i] = 0;
                i++;
            }else if(temp[i] == temp[j]){   // 匹配
                pmt[i] = j+1;
                i++, j++;
            }else{  // 在i,j处发生了失配
                j = pmt[j-1];   // 不断寻找次大匹配，企图找到最少回退步长
            }
        }
        int m = s.size();
        string re = rev.substr(0, m - pmt[n-1]) + s;
        return re;
    }
};

// int main(){
//     string s = "aacecaaa";
//     Solution ob;
//     string re = ob.shortestPalindrome(s);
//     cout<<re<<endl;
// }
// @lc code=end

