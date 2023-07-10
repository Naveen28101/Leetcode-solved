//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    struct Node* reverse(struct Node* head){
        if(head==NULL || head->next==NULL) return head;
        
        Node* prev=NULL;
        Node* curr=head;
        Node* nex;
        
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        
        head=prev;
        
        return head;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* ans=new Node(0);
        Node* temp=ans;
        int carry=0;
        Node* t1=reverse(first);
        Node* t2=reverse(second);
        
        while((t1 || t2) || carry){
            int sum=0;
            if(t1){
                sum+=t1->data;
                t1=t1->next;
            }
            if(t2){
                sum+=t2->data;
                t2=t2->next;
            }
            sum+=carry;
            carry=sum/10;
            temp->next=new Node(sum%10);
            temp=temp->next;
        }
        
        Node* final=reverse(ans->next);
        return final;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends