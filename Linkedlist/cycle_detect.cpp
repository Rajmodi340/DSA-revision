#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }

    if (slow != fast)
        return NULL;
    ListNode *p = head;
    while (p != slow)
    {
        p = p->next;
        slow = slow->next;
    }
    return slow;
}
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val;
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main(){
    int n;
    cin>>n;
    if(n<=0)
    return 0;
    int x;
    cin>>x;
ListNode*temp=new ListNode(x);
ListNode*curr=temp;
for(int i=1;i<n;i++){
    cin>>x;
    curr->next=new ListNode(x);
    curr=curr->next;
}
cout << "Original list:\n";
print(temp);
curr->next = temp->next;
ListNode *cycleNode = detectCycle(temp);
if (cycleNode == NULL)
    cout << "No cycle detected\n";
else
    cout << "Cycle starts at node with value: "
         << cycleNode->val << endl;
return 0;
}