#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    string st1 = "";
    string st2 = "";
    for (auto ch : word1)
    {
        st1 += ch;
    }
    for (auto ch : word2)
    {
        st2 += ch;
    }
    return st1 == st2;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>word1(n);
    vector<string>word2(m);
    for(int i=0;i<n;i++){
        cin>>word1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> word2[i];
    }
     bool num=arrayStringsAreEqual(word1,word2);
if(num){
    cout<<"1"<<"";
}
else{
    cout<<"0"<<"";
}
     return 0;
}