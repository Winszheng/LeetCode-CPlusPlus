// 子串模糊匹配
// 递归 - 只在‘？’的地方做递归，避免递归太深引起爆栈
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int l1, l2;

int resolve(string &s1, string &s2, int i, int j){
    while(i<l1 && j<l2 && s1[i] == s2[j]){
        i++, j++;
    }
    if(j==l2){
        // 匹配达到终点
        return i;
    }
    if(s2[j] == '?'){
        // 模糊查询
        int a = min(resolve(s1, s2, i+1, j+1), resolve(s1, s2, i+2, j+1));
        return min(a, resolve(s1, s2, i+3, j+1));
    }
    return INT_MAX;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    l1 = s1.size(), l2 = s2.size();
    
    int re = resolve(s1, s2, 0, 0);
    if(re == INT_MAX)cout<<"-1"<<endl;
    else cout<<re<<endl;
}