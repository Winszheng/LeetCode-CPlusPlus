#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>
using namespace std;

// vector list统计词频
// map - (词频, vector<string>)
// 虽然过了，但是时空效率很低

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> record; // 统计词频
        vector<vector<string>> re;  // 返回结果
        for(string s : strs){
            vector<int> temp(26);
            for(char c : s)temp[c-'a']++;
            bool f = false;
            for(int i=0; i<record.size(); i++){
                if(temp == record[i]){
                    re[i].push_back(s);
                    f = true;
                    break;
                }
            }
            if(!f){
                record.push_back(temp);
                re.push_back({s});
            }
        }
        return re;
    }
};

// int main(){
//     unordered_map<vector<int>, int> re;
// }