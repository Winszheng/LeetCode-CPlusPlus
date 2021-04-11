#include "895.最大频率栈.cpp"
#include <iostream>
using namespace std;

int main(){
    FreqStack f;
    f.push(4);f.push(0);f.push(9);f.push(3);f.push(4);f.push(2);
    cout<<f.pop();
    f.push(6);
    cout<<f.pop();
    f.push(1);
    cout<<f.pop();
    f.push(1);
    cout<<f.pop();
    f.push(4);
    cout<<f.pop();cout<<f.pop();cout<<f.pop();cout<<f.pop();cout<<f.pop();cout<<f.pop();
    
    return 0;
}