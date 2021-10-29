#include <vector>
#include <math.h>
using namespace std;
// 2 return 1
// 3 return 1*2 = 2
// 4 2*2 = 4
// 5 2*3 = 5
// 6 3*3 = 9
// 7 3*2*2 = 12
// 8 3*3*2 = 18
// 9 3*3*3 = 27
// 10 3*3*2*2 = 36

// 这道题最优做法是按数学规律来解
// 当能拆出尽可能多的3时，结果最优，如果能拆出1，就拿一个3出来补成4
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)return 1;
        if(n == 3)return 2;
        int a = n/3;
        int b = n%3;
        if(b == 0)return pow(3, a);
        else if(b == 1)return pow(3, a-1)*4;
        else {
            return pow(3, a)*2;
        }
    }
};
