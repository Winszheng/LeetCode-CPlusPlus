#include <string>
#include <iostream>
#include <vector>
using namespace std;

// 1.define fx : [0..x]的所有解
// 2.对每一个当前状态，只要当前状态不为零，就可以接收f(x-1)状态
// 接收前一个数字，只要状态在1-26中，就可以接收f(x-2)状态

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')return 0;
        int n = s.size();
        vector<int> dp(n); dp[0] = 1;
        for(int i=1; i<n; i++){
            if(s[i] != '0')dp[i] += dp[i-1];
            int tmp = (s[i-1]-'0')*10 + s[i]-'0';
            if(tmp>9 && tmp<27){
                if(i>1)dp[i] += dp[i-2];
                else dp[i]++;
            }
        }
        return dp[n-1];
    }
};

int main(){
    string str = "2101";
    Solution s;
    cout<<s.numDecodings(str)<<endl;
}