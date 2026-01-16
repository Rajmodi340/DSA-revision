#include<iostream>
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
ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    delete (slow);

    return head;
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
    ListNode *head = new ListNode(x);
    ListNode *curr = head;
     for (int i = 1; i < n; i++)
    {
        cin>>x;
        curr->next=new ListNode(x);
        curr=curr->next;
    }
    cout << "Original list:\n";
    print(head);
    head=deleteMiddle(head);
    print(head);
     return 0;
}