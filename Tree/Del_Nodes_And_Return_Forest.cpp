#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
class TreeNode{
    public: 
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data){
    val=data;
    left=NULL;
    right=NULL;
    }
};
TreeNode *deletehelper(TreeNode *root, unordered_set<int> &st, vector<TreeNode *> &result)
{
    if (!root)
        return NULL;
    root->left = deletehelper(root->left, st, result);
    root->right = deletehelper(root->right, st, result);
    if (st.find(root->val) != st.end())
    {
        if (root->left != NULL)
            result.push_back(root->left);
        if (root->right != NULL)
            result.push_back(root->right);
        return NULL;
    }
    else
    {
        return root;
    }
}
vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
{
    vector<TreeNode *> result;
    unordered_set<int> st;
    for (auto num : to_delete)
    {
        st.insert(num);
    }
    deletehelper(root, st, result);
    if (st.find(root->val) == st.end())
        result.push_back(root);
    return result;
}
TreeNode*buildtree(){
    int x;
    cin>>x;
    if(x==-1)
    return NULL;
    TreeNode*root=new TreeNode(x);
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*curr=q.front();
        q.pop();
    int leftval;
    cin>>leftval;
    if(leftval!=-1){
curr->left=new TreeNode(leftval);
q.push(curr->left);
    }
    int rightval;
    cin>>rightval;
    if(rightval!=-1){
        curr->right=new TreeNode(rightval);
        q.push(curr->right);
    }
}
return root;
}
void preorder(TreeNode*root){
    if(!root)
    return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    TreeNode*root=buildtree();
    int k;
    cin>>k;
    vector<int>del(k);
    for(int i=0;i<k;i++){
        cin>>del[i];
    }
    vector<TreeNode *> result = delNodes(root,del);
    for(auto num:result){
        preorder(num);
        cout<<endl;
    }
     return 0;
}