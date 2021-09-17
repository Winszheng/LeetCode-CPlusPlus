#include <sstream>
#include <iostream>
using namespace std;

int main(){
    string s = "a b c d";
    stringstream ss;
    ss.str(s);
    string a, b, c, d;
    ss>>a>>b>>c>>d; // 相当于cin赋值abcd
    cout<<a<<endl;// ab
}