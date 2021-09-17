#include <string>
#include <vector>
using namespace std;

// 考察哈希表的基本使用
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s == t || s.size() != t.size())return false;
        vector<int> a(26), b(26);
        for(char c : s)a[c-'a']++;
        for(char c : t)b[c-'a']++;
        return a==b;
    }
};