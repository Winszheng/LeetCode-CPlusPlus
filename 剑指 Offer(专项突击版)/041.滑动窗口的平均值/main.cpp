#include <vector>
#include <numeric>
using namespace std;

// 求滑动窗口平均值
class MovingAverage {
    int cap;
    vector<int> win;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        cap = size;
    }
    
    double next(int val) {
        if(win.size() == cap){
            win.erase(win.begin());
        }
        win.push_back(val);
        int n = win.size();
        int sum = accumulate(win.begin(), win.end(), 0);
        return 1.0*sum/n;
    }
};
