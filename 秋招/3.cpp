// 连续的0 1序列，返回大的那个
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
// scanf("%1d", &n);
// 78.95
// 解决这个可能要用dp
int main(){
    int n, num;  // 长度为n的串
    int sumofone=0, sumofzero=0;
    int lastone=0, lastzero=0;
    char c;
    cin >> n;
    for(int i=0;i<n;i++){
        // scanf("%d", &num);
        cin >> c;
        num = c-'0';
        if(num==0){
            sumofzero++;
            lastzero=i;
        }else{
            sumofone++;
            lastone=i;
        }
    }

    // cout<<sumofone<<lastone<<endl;  // 5
    // cout<<sumofzero<<lastzero<<endl;    // 4
    
    int ta = n-lastone-1;
    int tb = n-lastzero-1;
    int a = (1+sumofone)*sumofone/2 + (1+ta)*ta/2;
    int b = (1+sumofzero)*sumofzero/2 + (1+tb)*tb/2;

    cout<<max(a, b)<<endl;
    
}