#include <vector>
#include <string>
#include <stack>
using namespace std;

// 这道题，相当于在求直方图最大矩形上套了一层循环

class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        if(matrix.size() == 0)return 0;
        int n = matrix.size(), m = matrix[0].size(), re = 0;
        vector<int> hh(m+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                hh[j] = matrix[i][j]=='0' ? 0 : hh[j]+1; // 构造当前直方图
            }
            stack<int> s;
            for(int j=0; j<m+1; j++){
                while(!s.empty() && hh[s.top()] > hh[j]){
                    int h = hh[s.top()]; s.pop();
                    int w = s.empty() ? j : j-s.top()-1;
                    re = max(re, h*w);
                }
                s.push(j);
            }
        }
        return re;
    }
};
// 0 1
// 1 0