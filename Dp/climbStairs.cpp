#include <iostream>
#include <cstring>
using namespace std;

int t[101];

int solve(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    if (t[n] != -1)
        return t[n];

    return t[n] = solve(n - 1) + solve(n - 2);
}

int climbStairs(int n)
{
    std::memset(t, -1, sizeof(t));
    return solve(n);
}

int main()
{
    int n;
    cin >>n;
    cout << climbStairs(n);
    return 0;
}
