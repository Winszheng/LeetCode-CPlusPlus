// 这道题我一定做过，只是在哪呢...忘记了
#include <queue>
#include <iostream>
using namespace std;

void work(){
    int n;
    cin >> n;
    queue<int> q;
    for(int i=0;i<n;i++){
        string op;
        cin>>op;
        if(op == "PUSH"){
            int t;
            cin>>t;
            q.push(t);
        }else if(op == "TOP"){
            cout<< q.front() << endl;
        }else if(op == "POP"){
            if(q.size() == 0)cout<<"-1"<<endl;
            else q.pop();
        }else if(op == "SIZE")cout<<q.size()<<endl;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)work();
    return 0;
}