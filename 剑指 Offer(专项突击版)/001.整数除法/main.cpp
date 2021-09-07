#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        if(a==INT_MAX && b==-1)return INT_MAX;
        if(a==INT_MAX && b==1)return INT_MAX;
        if(a==INT_MIN && b==1)return INT_MIN;
        if(a==INT_MIN && b==-1)return INT_MAX;

        bool flag;
        if((a>=0 && b>0) || (a<0 && b<0))flag = true;
        else flag = false;

        int re = 0;
        long long ta = abs((long long)a), tb = abs((long long)b);

        while(ta >= tb){    
            long long t = tb;
            int i = 1;
            while(t+t <= ta){   // t+t溢出成为负数，导致进入死循环
                t += t;
                i += i;
            }
            cout<<"here"<<endl;
            ta -= t;
            re += i;
        }

        if(!flag)re = -re;
        return re;
    }
};

int main(){
    Solution s;
    cout<<s.divide(-2147483648, -1)<<endl;
    cout<<s.divide(15, 2)<<endl;
    cout<<s.divide(7, -3)<<endl;
    cout<<s.divide(0, 1)<<endl;
    cout<<s.divide(1, 1)<<endl;
    cout<<s.divide(2147483647, 1)<<endl;
    cout<<s.divide(-2147483648, 1)<<endl;
    cout<<s.divide(2147483647, 2)<<endl;
}

// [1]    14625 floating point exception (core dumped)