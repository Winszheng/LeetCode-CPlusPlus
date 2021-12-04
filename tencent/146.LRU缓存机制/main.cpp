// 去你妈的

class LRUCache {
public:
    LRUCache(int capacity) {

    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
};

int main() {
    LRUCache s(2);
    s.put(1, 1); s.put(2, 2);
    cout<<s.get(1)<<endl;
    s.put(3, 3);
    s.get(2);
    s.put(4, 4);
    s.get(1);
    // s.get(3);
    // s.get(4);

}