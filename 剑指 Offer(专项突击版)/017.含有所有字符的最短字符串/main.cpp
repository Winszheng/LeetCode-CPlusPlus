#include <string>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// 017.最小覆盖子串
// 两个vector
// 一个target表征每个字符出现的频率
// 一个current，表征当前拥有的频率情况
// 一个need，表征需要字符的数量
// 每次探索一个字符，如果这个字符在current中的频率比target小，加入窗口，need--
// 否则，current中频率++
// 一旦need==0，表征找到了覆盖子串的当前解
// 收缩左侧，不断减去左侧字母在current中的频率

class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r=0, n=s.size(), need=t.size(), len=INT_MAX, index=0;
        if(need > n)return "";

        vector<int> target(128), current(128);
        for(char c : t)target[c]++;
        
        while(r<n){
            current[s[r]]++;
            if(target[s[r]]!=0 && current[s[r]]<=target[s[r]])need--;
          
            while(need == 0){
                // 收缩左侧
                current[s[l]]--;
                if(current[s[l]] < target[s[l]]){
                    need++; //找到一个缺口
                    if(r-l+1 < len){
                        len = r-l+1;
                        index = l;
                    }
                }
                l++;
            }
            r++;
        }
        
        // 因为len是INT_MAX，超过了能赋的值，因此，相当于把能获取的都获取的了，才会把本应是空串的变成a
        if(len == INT_MAX)return "";
        return s.substr(index, len);
    }
};

int main(){
    Solution s;
    cout<<s.minWindow("ADOBECODEBANC", "ABC")<<endl;
    cout<<s.minWindow("a", "b")<<endl;
    return 0;
}

