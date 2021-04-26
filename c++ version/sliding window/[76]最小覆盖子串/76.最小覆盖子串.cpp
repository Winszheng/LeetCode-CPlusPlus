/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
// s t 只有英文字母
// 看起来很复杂，想起来还是比较简单的
// need - 记录还需要找几个字母
// length - 记录覆盖子串长度，先随便赋值一个最大的数
// 某种程度上，temp可以看成target的溢出
// tl - 记录最左元素
// 之前不过的原因是没考虑把need == 0加到while循环的条件
// 事实上，当匹配的子串在s的末尾时，这样可以多跑一遍else分支，找到相应子串
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())return "";
        vector<int> target(128, 0), temp(128, 0);
        int need = t.size(), l = 0, r = 0; // 初始滑动窗口, 按情况选0或-1
        int length = INT_MAX, tl = 0;   // INT_MAX和INT_MIN分别表示最大、最小整数
        for(char c : t)target[c]++;
        while( r < s.size() || need == 0){
            if(need > 0){   // 这在寻找能覆盖的序列
                if(temp[s[r]] < target[s[r]]){
                    need--;
                }
                temp[s[r++]]++;
            }else{
                while(need == 0){
                    temp[s[l]]--;
                    if(temp[s[l]] < target[s[l]]){
                        need++; // 找到一个相对窄序列
                        if(r-l <length){    // <=也能过
                            length = r-l;
                            tl = l; // target_length
                        }
                    }
                    l++;
                }
            }
        }
        if(length == INT_MAX)return "";
        return s.substr(tl, length);
    }
};
// @lc code=end

