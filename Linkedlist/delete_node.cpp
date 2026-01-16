#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int data){
    val=data;
    next=NULL;
    }
};
void deleteNode(ListNode *node)
{
    ListNode *prev = NULL;
    while (node && node->next)
    {
        node->val = node->next->val;
        prev = node;
        node = node->next;
    }
    delete (node);
    prev->next = NULL;
}
void print(ListNode*head){
    ListNode*temp=head;
    while(temp!=NULL){
        cout<<temp->val;
        temp=temp->next;
    }
    cout<<"NULL";
}
int main(){
    int n;
    cin>>n;
    if(n<=0)
    return 0;
    int x;
    cin>>x;
    ListNode*head=new ListNode(x);
    ListNode*curr=head;
    for(int i=1;i<n;i++){
        cin>>x;
        curr->next= new ListNode(x);
        curr=curr->next;
        
    }
    cout << "Original list:\n";
    print(head);
    int delval;
    cin>>delval;
curr=head;
while(curr!=NULL&&curr->val!=delval){
    curr=curr->next;
}

if (curr == NULL || curr->next == NULL)
{
    cout << "Cannot delete this node using this method\n";
}
else
{
    deleteNode(curr);
    cout << "After deletion:\n";
    print(head);
}
    return 0;
}