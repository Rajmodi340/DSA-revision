#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return {};
    int row = matrix.size();
    int col = matrix[0].size();
    int top = 0;
    int bottom = row - 1;
    int left = 0;
    int right = col - 1;
    int id = 0;
    vector<int> result;
    while (left <= right && top <= bottom)
    {
        if (id == 0)
        {
            for (int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;
        }
        if (id == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;
        }

        if (id == 2)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (id == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        id = (id + 1) % 4;
    }
    return result;
}
    int main()
    {
        int n, m;
        cin >> m >> n; // m = rows, n = columns

        vector<vector<int>> a(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        vector<int> ans = spiralOrder(a);

        for (int x : ans)
        {
            cout << x << " ";
        }
        return 0;
    }