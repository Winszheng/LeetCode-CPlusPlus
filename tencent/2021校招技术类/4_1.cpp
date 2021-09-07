#include <vector>
#include <iostream>
using namespace std;

void work(){
    int n;
    cin >> n;
    vector<int> q;

    for(int i=0;i<n;i++){
        string op;
        cin >> op;
        
        if(op == "TOP"){
            if(q.size() == 0)cout<<-1<<endl;
            else cout<<q[0]<<endl;
        }else if(op == "POP"){
            if(q.size() == 0)cout<<-1<<endl;
            else q.erase(q.begin());
        }else if(op == "SIZE"){
            cout<<q.size()<<endl;
        }else if(op == "PUSH"){
            int t;cin>>t;
            q.push_back(t);
        }else q.clear();
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)work();
}