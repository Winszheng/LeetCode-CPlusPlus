// t = (x+y+c)%2
// c = (x+y+c)/2
// 朴素的进位运算，注意最后可能多出一位就没别的了

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size()-1, m = b.size()-1;
        int c = 0;
        string re;
        while(n>=0 && m>=0){
            re = to_string((a[n]-'0'+b[m]-'0'+c)%2) + re;
            c = (a[n]-'0'+b[m]-'0'+c)/2;
            n--, m--;
        }
        while(n>=0){
            re = to_string((a[n]-'0'+c) % 2)+re;
            c = (a[n]-'0'+c) / 2;
            n--;
        }
        while(m>=0){
            re = to_string((b[m]-'0'+c) % 2)+re;
            c = (b[m]-'0'+c) / 2;
            m--;
        }
        if(c == 1){
            re = '1'+re;
        }
        return re;
    }
};

int main(){
    Solution s;
    cout<<s.addBinary("1", "111")<<endl;
}