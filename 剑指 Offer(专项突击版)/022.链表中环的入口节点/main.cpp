// 判断是否有环并返回结果
#include <unordered_set>
using namespace std;

// 1.哈希表存储每个节点，查看有无重复——需要开辟O(n)的内存空间，时空效率都很低，但代码省事
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *t = head;
        unordered_set<ListNode*> re;
        int i = 0;
        while(t){
            if(re.find(t) == re.end()){
                re.insert(t);
                t = t->next;
            }else{
                return t;
            }
        }
        return NULL;
    }
};