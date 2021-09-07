#include <iostream>
using namespace std;
// 运行时间：531ms
// 占用内存：408KB
// 因为嫌弃dp
int a, b, c;

int resolve(int n){
    if(n<0)return 0;
    if(n==0)return 1;
    return resolve(n-a)+resolve(n-b)+resolve(n-c);
}
int main(){
    int re = 0;
    int n;
    cin >> n >>a>>b>>c;
    re += resolve(n-a);
    re += resolve(n-b);
    re += resolve(n-c);
    cout<<re<<endl;
}