/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
// 直接找了题解
// 思路不难，细节不少，主要考察各种语言对字符串的处理
// stringstream支持对string对象更灵活的处理
// getline把字符流写入特定的字符串，直到遇到分隔符,分隔符不设置默认为回车

#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> record;
        string re, temp;
        stringstream is(path);  // 把path转换成待处理的输入流
        while(getline(is, temp, '/')){  // 在oj eof之前不会停止
             // 根目录or当前目录or多条'/'时，不需要处理record
            if(temp == "" || temp == ".")continue; 
            if(temp == ".." && !record.empty())record.pop_back();
            else if(temp != "..")record.push_back(temp);
        }
        for(string s : record)re+="/"+s;
        if(record.empty())re = "/";
        return re;
    }
};
// @lc code=end

