#include <unordered_map>
#include <iostream>
using namespace std;

// 本题的练习目的：构造以双向链表为底层的哈希表
// 做到插入、删除、访问的复杂度都是1

// 过了，时空效率都比较理想
// 操作和单链表本质是一样的，要注意的点是：
// 1.因为要操作的指针变多了，不要吝啬对指针变量的使用，免得pre来next去发生了错误
// 2.插入、删除记得需要修改哈希表
struct Node{
    int key, val;
    Node *next, *pre;
    Node(int k, int v){
        key = k;
        val = v;
        next = NULL, pre = NULL;
    }
};

class LRUCache {
    unordered_map<int, Node*> cache;
    int size;
    int cap;
    Node *hh, *tail;// 假头结点、假尾节点，目的是为了方便操作
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        hh = new Node(-1, -1), tail = new Node(-1, -1);
        hh->next = tail, tail->pre = hh;
    }
    
    int get(int key) {
        // 1.不存在，返回-1
        // 2.存在，调整成尾节点(真正的尾节点), 并返回相应值
        if(!cache.count(key))return -1;
        Node *t = cache[key];
        Node *a = t->pre, *b = t->next;
        a->next = b, b->pre = a;
        Node *pretail = tail->pre;
        pretail->next = t; t->pre = pretail;
        t->next = tail; tail->pre = t;
        return t->val;
    }
    
    void put(int key, int value) {
        // 1.存在，调整值
        // 2。不存在，插入，插入如果溢出，要删除
        if(cache.count(key)){
            cache[key]->val = value;
            get(key);
        }else{
            Node *pretail = tail->pre;
            Node *t = new Node(key, value);
            pretail->next = t;t->pre = pretail;
            t->next = tail; tail->pre = t;
            size++;
            cache[key] = t;
            if(size > cap){
                Node *nexthh = hh->next;
                hh->next = nexthh->next;
                nexthh->next->pre = hh;
                cache.erase(nexthh->key);
            }
        }
    }
};
