#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Build tree using level order input
TreeNode *buildTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    TreeNode *root = new TreeNode(x);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1)
        {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        cin >> rightVal;
        if (rightVal != -1)
        {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

// Your preorder logic
void preorder(TreeNode *root, int level, vector<int> &result)
{
    if (!root)
        return;

    if (result.size() < level)
    {
        result.push_back(root->val);
    }

    preorder(root->right, level + 1, result);
    preorder(root->left, level + 1, result);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> result;
    preorder(root, 1, result);
    return result;
}

int main()
{
    cout << "Enter tree values (level order, -1 for NULL):\n";

    TreeNode *root = buildTree();

    vector<int> ans = rightSideView(root);

    cout << "Right Side View: ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
