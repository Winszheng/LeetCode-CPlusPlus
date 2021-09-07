#include <iostream>
#include <vector>
using namespace std;
// vector<int> temp{1, 3, 4};
// temp.insert(temp.begin()+1, 2); 是插在前面
// 应该又会超时
// insert不太会用
int main(){
   int n, l, r;
   cin>>n>>l>>r;
   vector<int> temp(1);temp[0]=n;
   int nn = temp.size();

//    while(1){

//    }
   for(int i=0;i<nn;i++){
       if(temp[i]>1){
           int t = temp[i]/2, mod = temp[i]%2;
           temp[i] = mod;
           temp.insert(temp.begin()+i, t);
           temp.insert(temp.begin()+i+2, t);
           i=-1;
       }
       
       nn = temp.size();
    //    cout<<nn;
   }

    int re = 0;

    for(int i=0;i<nn;i++)cout<<temp[i];
    cout<<endl;

   for(int i=l;i<=r;i++){
       if(temp[i]==1)re++;
   }
   cout<<re<<endl;
   
    
}