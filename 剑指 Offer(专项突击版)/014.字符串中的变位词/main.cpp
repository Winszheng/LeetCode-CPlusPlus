#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int n = s1.size(), m=s2.size();
       if(m<n)return false;
       vector<int> m1(128), m2(128);
       for(char c: s1)m1[c]++;
       for(int i=0;i<n;i++)m2[s2[i]]++;015. 字符串中的所有变位词
       if(m1 == m2)return true;

       for(int i=0; i<m-n; i++){
           cout<<s2[i]<<","<<s2[i+n]<<endl;
           m2[s2[i]]--;m2[s2[i+n]]++;
           if(m1 == m2)return true;
       }
       return false;
    }
};

int main(){
    Solution s;
    cout<<s.checkInclusion("ab", "eidbaooo")<<endl;
}
// int main(){
//     vector<int> tmp1{1,2,3}, tmp2{1,2,3};bool v1 = tmp1==tmp2;
//     map<string, int> map1{{"mary",12},{"peter",13}}, map2{{"mary",12},{"peter",13}};bool m1 = map1==map2;
//     unordered_map<string, int> umap1{{"mary",12},{"peter",13}}, umap2{{"mary",12},{"peter",13}};bool um1 = umap1==umap2;
//     set<int> s1{1,2,3}, s2{1,2,3};bool se = s1==s2;
//     unordered_set<int> us1{1,2,3}, us2{1,2,3};bool use = us1==us2;
//     cout<<"vector:"<<v1<<endl;
//     cout<<"map:"<<m1<<endl;
//     cout<<"umap:"<<um1<<endl;
//     cout<<"set:"<<se<<endl;
//     cout<<"uset:"<<use<<endl;
//     return 0;
// }