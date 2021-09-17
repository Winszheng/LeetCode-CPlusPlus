#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

// 因为要求平均时间复杂度1
// 为了避免删除元素带来的下标问题，解决的方法是交换:
// 每当需要删除一个元素，把末尾下标的元素放到需要删除元素的位置，然后vector直接pop_back
// 而哈希表中，末尾元素的坐标改成应删除元素的坐标，然后erase应删除元素
class RandomizedSet {
    unordered_map<int, int> re; // 数值 下标
    vector<int> v;  // 下标 数值
public:
    RandomizedSet() {}

    bool insert(int val) {
        if(!re.count(val)){
            v.push_back(val);
            re[val] = v.size()-1;
            return true;
        }
        return false;
    }
    
    // 注意这种通过把应删除元素和末端交换再删除的做法，需要改好信息再删除
    // 避免因为本来就是末端，有可能会造成麻烦
    bool remove(int val) {
        if(re.count(val)){
            int last = v.back();
            // 因为val和last有可能是相同的！所以不能先删除val, 否则会出错
            re[last] = re[val];
            v[re[last]] = last;

            re.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};
