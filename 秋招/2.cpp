// 按因子数决定胜利
// #include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

// 超时 - 40
// 这道题的关键是：我求因数的方法太粗暴了
// 参考507 完美数

int work(int n){
    if(n < 3)return n;
    int num = 2;
    for(int i=2; i<=n/2; i++){ // 这里可能有问题
        if(n % i == 0)num++;
    }
    return num;
}
int main(){
    int n, t;
    cin >> n;
    vector<int> a, b;
    for(int i=0;i<n;i++){   // 我
        cin>>t;
        a.push_back(work(t));
    }
    for(int i=0;i<n;i++){   // 对手
        cin>>t;
        b.push_back(work(t));
    }
    sort(a.begin(), a.end());sort(b.begin(), b.end());
    
    for(int i=0;i<n;i++)cout<<a[i];
    cout<<endl;
    for(int i=0;i<n;i++)cout<<b[i];
    cout<<endl;

    int re = 0;
    int i=0, j=0;
    while(i < n){
        if(a[i]>b[j]){  // 找到一个结果
            re++;
            i++, j++;
        }else i++;
    }
    cout<<re<<endl;
}
