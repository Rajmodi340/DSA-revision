#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> leftmax(n);
    vector<int> rightmax(n);
    leftmax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(leftmax[i - 1], height[i]);
    }

    rightmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(rightmax[i + 1], height[i]);
    }
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        int minheight = min(leftmax[i], rightmax[i]);
        if (minheight >= height[i])
            water += minheight - height[i];
    }
    return water;
}
    int main()
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
        cin>>a[i];}
       int result= trap(a);
       cout<<result<<"";
        return 0;
    }