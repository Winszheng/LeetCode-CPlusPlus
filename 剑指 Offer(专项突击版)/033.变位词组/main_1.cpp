#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
// 哈希表 - (排列，下标)
// 循环，每个string都先做排序，查看这个排列是否存在哈希表。
// 不存在，把(排列, 下标)存入哈希表， 字符串压入数组
// 存在，则压入对应数组

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> re;
        unordered_map<string, int> temp;
        for(string s : strs){
            string k = s;
            sort(k.begin(), k.end());
            if(temp.count(k)){
                re[temp[k]].push_back(s);
            }else{
                temp[k] = re.size();
                re.push_back({s});
            }
        }
        return re;
    }
};