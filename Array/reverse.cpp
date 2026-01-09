#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void reverse(vector<int>&a){
    int n=a.size();
    int start=0;
    int end=n-1;
    while(start<end){
        swap(a[start],a[end]);
        start++,end--;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    reverse(a);
    for (int x : a)
    {
        cout << x << " ";
    }
    return 0;
}