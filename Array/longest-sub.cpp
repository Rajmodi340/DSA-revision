#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binaarysearch(vector<int> &nums, int n, int query)
{
    int l = 0;
    int r = n - 1;
    int idx = -1;
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] <= query)
        {
            idx = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return idx + 1;
}
vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> result;
    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }
    for (int query : queries)
    {
        int count = binaarysearch(nums, n, query);
        result.push_back(count);
    }
    return result;
}
int main(){
    int n ,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<int> ans = answerQueries(a,b);
    for(int x:ans){
        cout<<x<<"";
    }
     return 0;
}