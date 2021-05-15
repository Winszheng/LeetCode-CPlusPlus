/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
// 给一串数字，返回所有可能的ip地址
// 思路不难，细节不少
// 这个题本质上和17.电话号码的字母组合是一样的
// 虽然不是树形的，但是也是典型的回溯题

class Solution {
    void resolve(vector<string>& re, string s, int index, string temp, int flag){
        if(flag == 4){
            string ss = s.substr(index, s.size()-index);    // 截取字符串
            int t = stoi(ss);   // str转int
            if(ss.size() == 1 || (t>=0 && t <= 255 && ss[0] != '0')){
                temp += ss;
                re.push_back(temp); // 找到一个结果
            }
            return;
        }

        for(int i = 1; i < 4 && i+index<s.size(); i++){ // 避免越界 
            string ss = s.substr(index, i);
            int t = stoi(ss);
            if(i==1 || (t>=0 && t<=255 && ss[0] != '0')){
                resolve(re, s, index+i, temp+ss+".", flag+1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> re;
        if(s.size() < 4 || s.size() > 12)return re;
        resolve(re, s, 0, "", 1);
        return re;
    }
};

// @lc code=end

