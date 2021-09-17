#include <queue>
using namespace std;

// 时空效率非常高，比直接vector一重循环好很多

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t-3000)q.pop();
        return q.size();
    }
};
