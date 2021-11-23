#include <vector>
#include <algorithm>
using namespace std;
// fi 表以第i个信封为最外层，能嵌套的层数
// hard
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n, 1); 
        int re = 1;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                    if(dp[i]-re == 1){
                        re++; break;
                    }
                }
            }
        }
        return re;
    }
};

