#include <stack>
#include <iostream>
#include <vector>
using namespace std;

vector<stack<int>> a;
class DinnerPlates {
    int ca;
    
public:
    DinnerPlates(int capacity) {
        ca = capacity;
        stack<int> b;
        a.push_back(b);
    }
    
    void push(int val) {
        for(int i=0; i<a.size();i++){
            if(a[i].size() == ca){
                

                continue;
            }else{
                a[i].push(val);
                return;
            }
        }
        stack<int> b;
        a.push_back(b);
        a[a.size()-1].push(val);
    }
    
    int pop() {
        // 用这个判断的前提是，会删掉vector的元素，因为不删，所以没用了
        // if(a.size() == 0) return -1;

        int index = a.size() - 1;
        while(index >=0 && a[index].size() == 0)index--;
        if(index < 0 ) return -1;
        
        int x = a[index].top();
        a[index].pop();
        // if(a[a.size()-1].size() == 0)a.pop_back();
        return x;
    }
    
    int popAtStack(int index) {
        if(index >= a.size() || a[index].size() == 0 ) {
            return -1;
        }
        int x = a[index].top();
        
        a[index].pop();
        // if(a[index].size() == 0){
        //     a.erase(a.begin() + index);
        // }
        return x;
    }   
};

int main(){
    //  test3
    DinnerPlates p(2);
    p.push(1);
    p.push(2);p.push(3);p.push(4);p.push(5);
    cout<<p.popAtStack(0);
    p.push(20);p.push(21);
    cout<<p.popAtStack(2);
    p.pop();p.pop();p.pop();p.pop();p.pop();

    // test2 —— 搞半天空栈不用删掉啊
    // DinnerPlates p(1);
    // p.push(1);
    // p.push(2);
    // cout<<p.popAtStack(0);
    // cout<<p.popAtStack(1);
    // p.push(3);
    // cout<<p.popAtStack(0);

    // // test1
    // DinnerPlates p(2);
    // p.push(1);
    // p.push(2);
    // p.push(3);
    // p.push(4);
    // p.push(7);
    // cout<<p.popAtStack(8)<<", ";
    // p.push(20);
    // p.push(21);
    // cout<<p.popAtStack(0)<<", ";
    // cout<<p.popAtStack(2)<<", ";
    // cout<<p.pop()<<", ";
    // cout<<p.pop()<<", ";
    // cout<<p.pop()<<", ";
    // cout<<p.pop()<<", ";
    // cout<<p.pop()<<endl;
}