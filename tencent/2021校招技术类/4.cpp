// 过不了
// 唯一能想到的可能，就是本题隐含条件不准用queue
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
            int si = q.size();
            if(si==0)cout<<-1<<endl;
            cout<< q.front() << endl;
        }else if(op == "POP"){
            int si = q.size();
            if(si == 0)cout<<"-1"<<endl;
            else q.pop();
        }else if(op == "SIZE"){
            cout<<q.size()<<endl;
        }else if(op == "CLEAR"){
            while(q.size() > 0)q.pop();
        }
    }
}
int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++)work();
    
    return 0;
}