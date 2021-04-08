// delete and return the element
class CQueue {
    stack<int> a, b;
    void in2out(){
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
    }
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if(b.empty()){
            if(a.empty())return -1;
            else in2out();
        }
        int x = b.top();
        b.pop();
        return x;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */