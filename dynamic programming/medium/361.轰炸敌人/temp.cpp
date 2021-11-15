// 10101010 = 170
// 计算有多少个1
#include <iostream>
using namespace std;

// 规律： i&(i-1)能将i的二进制最右变成0
int main(){
    int re = 0;
    int i = 170;
    while(i != 0){
        re++;
        i = i & (i-1);
    }
    cout<<re<<endl;
}