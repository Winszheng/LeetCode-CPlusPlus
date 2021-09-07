// 因为只有26个字母，所以可以用int的26位表征字母的存在性

#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> re(n);
        for(int i=0;i<n;i++){
            for(char c : words[i]){
                int t = pow(2, c-'a');
                re[i] = re[i] | t;
            }
        }
        int ret = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a = re[i] & re[j];
                int b = words[i].size() * words[j].size();  // 改了这里就过了，tmd，为什么
                if( a == 0)ret = max(ret, b);
            }
        }
        return ret;
    }
};