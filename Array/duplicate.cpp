#include<iostream>
#include<vector>
// #include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void duplicate(vector<int>&a){
    sort(a.begin(),a.end());
    int n=a.size();
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            cout<<a[i];
        }
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout<<"enter the element of array";
    for(int i=0;i<3;i++){
    cin>>a[i];
    }
    duplicate(a);

    return 0;
}