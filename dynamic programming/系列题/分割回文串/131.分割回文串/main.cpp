#include <vector>
#include <string>
#include <iostream>
using namespace std;

// 分割回文串的所有结果-深搜
// 过了，而且效率还不错
class Solution {
public:
    int n;
    vector<vector<string>> re;   
    string s; 
    bool isp(int i, int j){
        while(i < j){
            if(s[i] != s[j])return false;
            i++, j--;
        }
        return true;
    }
    // 处理生成回文串集合的函数
    void resolve(int index, vector<string>& temp){
        if(index == n){
            re.push_back(temp);
            return;
        }
        for(int j=index; j<n; j++){
            if(isp(index, j)){
                temp.push_back(s.substr(index, j-index+1));
                resolve(j+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       n = s.size(); this->s = s;
       vector<string> temp;
       resolve(0, temp);
       return re;
    }
};

int main(){
    Solution s; 
    string test1 = "aab";
    string test2 = "efe";
    string test3 = "abbab";
    vector<vector<string>> re = s.partition(test3);
    for(int i=0; i<re.size(); i++){
        for(int j=0; j<re[i].size(); j++)cout<<re[i][j]<<" ";
        cout<<endl;
    }
}