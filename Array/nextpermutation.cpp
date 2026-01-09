#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    int i = n - 1;
    for (; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            break;
        }
    }
    if (i != 0)
    {
        int index = i;
        for (int j = n - 1; j >= i; j--)
        {
            if (nums[j] > nums[i - 1])
            {
                index = j;
                break;
            }
        }
        swap(nums[i - 1], nums[index]);
    }
    reverse(nums.begin() + i, nums.end());
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    nextPermutation(a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}