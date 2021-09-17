#include <vector>
#include <string>
using namespace std;

// 返回字符串中所有变位词的起始索引
// vector+滑动窗口

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.size(), m=s.size();
        vector<int> re;
        if(m<n)return re;
        
        vector<int> need(26), win(26);
        for(char c : p)need[c-'a']++;
        int l=0;
        for(int r=0; r<m; r++){
            win[s[r]-'a']++;
            if(r>=n){
                win[s[l]-'a']--;
                l++;
            }           
            if(need == win)re.push_back(l);
        }
        return re;
    }
};  