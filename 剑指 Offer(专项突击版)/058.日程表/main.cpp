#include <map>
#include <iostream>
using namespace std;
// 思路：用map存储(start, end)
// 遍历，查询lower_bound

// 然而效率不高
class MyCalendar {
public:
    map<int, int> re;   // start, end
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = re.upper_bound(start);
        // 有无与下一个时间重合
        if(it != re.end() && end>it->first) return false;
        // 有无与上一个时间段重合
        if(it != re.begin() && start < (--it)->second) return false;

        re[start] = end;
        return true;
    }
};

