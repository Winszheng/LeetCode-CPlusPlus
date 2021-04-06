#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

// 改良版：使用括号的成对关系(映射)

class Solution {
public:
    bool isValid(string s) {
       unordered_map<char, char> pair = {
           {')','('},
           {']','['},
           {'}','{'},
       };
       stack<char> ch;

       for(char c : s){
           // 判断key是否存在
           if(pair.count(c)){
               if(ch.empty() || ch.top() != pair[c])return false;
               ch.pop();
           }else{
               ch.push(c);
           }
       }

       return ch.empty();
    }
};