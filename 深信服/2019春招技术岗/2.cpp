// 我也不清楚这算排列还是组合 - 就都当成排列组合吧
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ball;
int k;

// index - 表要操作的球的种类
// n - 表还需要操作几个球
// s表当前结果
// 递归似乎常常可以做成多叉树的思路 - 是一种扁平的dp

void resolve(int index, int n, string s){
    if(n==0){
        while(s.size() < k)s+=to_string(0); //
        cout<<s<<endl;
        return;
    }

    if(index==k)return;

    for(int i=0;i<=ball[index];i++){
        if(i<=n)resolve(index+1, n-i, s+to_string(i));
    }
}

int main(){
    int n;
    cin >> k >> n;  // 知识点：c++块级作用域
    ball = vector<int>(k);
    for(int i=0;i<k;i++)cin >> ball[i];
    resolve(0, n, "");
    
}