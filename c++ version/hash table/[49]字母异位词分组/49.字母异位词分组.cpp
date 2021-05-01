/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
// 字母异位词分组
// anagram
#include <string>
#include <vector>
using namespace std;
// 优化：
// 由于anagram包含的字母是一样的，因此，对anagram做排序得到的结果肯定是一样
// 那么就可以拿来做键
// 查的是映射关系，所以用map

// Your runtime beats 50.94 % of cpp submissions
// Your memory usage beats 23.43 % of cpp submissions (20.1 MB)
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> record;
       vector<vector<string>> re;
       for(string s : strs){
           string key = s;
           sort(key.begin(), key.end());
           record[key].push_back(s);
       }
       for(auto r : record){
           re.push_back(r.second);
       }
       return re;
    }
};
// @lc code=end

