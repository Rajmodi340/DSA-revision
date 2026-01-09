#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;
vector<int> intersection(vector<int>&a,vector<int>&b){
    unordered_map<int, int> mp;
    vector<int>ans;
    for(auto &it:a)
mp[it]++;
for(auto  &it:b){
    if(mp.count(it)){
        ans.push_back(it);
        mp.erase(it);
    }
}
return ans;
}
int main(){
    int n;
    int m;
    cout << "Enter number of n: ";
    cin >> n;
    vector<int> a(n);

    cout << "enter the value of m";
    cin >> m;
    vector<int>b(m);
   
for(int i=0;i<n;i++){
   cin>>a[i];
}
for (int i = 0; i < m; i++)
{
    cin >> b[i];
}
vector<int>result=intersection(a,b);
for(int x:result){
    cout<<x<<"";
}
    return 0;
}
