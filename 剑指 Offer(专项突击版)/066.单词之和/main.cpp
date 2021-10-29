#include <unordered_map>
#include <string>
using namespace std;
// 单词之和 —— 求前缀权值之和
// 方法1：直接用哈希表
// 用一个哈希表记录键值，每次插入，直接更新
// 求sum时，遍历哈希表求和

// 如果用前缀树，那么就加一个字段用来表示前缀权值，每次插入时更新
// 至于求结果时，便利到prefix的末尾时，进行广度优先遍历，并加和
class MapSum {
public:
    unordered_map<string, int> re;
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        re[key] = val;
    }
    
    int sum(string prefix) {
        int num = 0, n = prefix.size();
        for(auto o : re){
            if(o.first.size() < n)continue;
            string t = o.first.substr(0, n);
            if(t == prefix)num += o.second;
        }
        return num;
    }
};