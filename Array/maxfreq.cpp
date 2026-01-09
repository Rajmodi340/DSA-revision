#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int>maxfreq(vector<int>&a){
    unordered_map<int,int>mp;
    vector<int>ans;
    int maxi=0;
    int n=a.size();
    for(auto &it:a){
        mp[it]++;
        maxi=max(maxi,mp[it]);
    }
    for(auto it:mp){
        if(it.second==maxi){
            ans.push_back(it.first);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>result=maxfreq(a);
    for(int x:result)
    cout<<x<<"";
    return 0;
}