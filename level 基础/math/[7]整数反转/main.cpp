#include <iostream>
#include <limits.h>
using namespace std;
// [INT_MIN, INT_MAX]
// [-2147483648, 2147483647]
// C语言取余，余数符合和被除数保持一致
// 负零和正零都是零

// 环境不允许存储64位整数

// 这道题不应该用字符串做，这样就失去了算法的意义
class Solution {
public:
    int reverse(int x) {
        int re = 0, pop;
        while(x != 0){
            pop = x % 10; x/=10;
            if(re > INT_MAX/10 || (re==INT_MAX/10 && pop > 7))return 0;     
            if(re < INT_MIN/10 || (re==INT_MIN/10 && pop < -8))return 0;       
            re = re*10 + pop;
        }
        return re;
    }
};

int main(){
    Solution s;
    cout<<s.reverse(123)<<endl;

    int re = -11;
    cout<< re%2<<endl;  // -1
    cout<< re%-2<<endl; // -1    
    cout<< re%11<<endl; //  0    
    cout<< re%-11<<endl; // 0    

}