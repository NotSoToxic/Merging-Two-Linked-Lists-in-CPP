#include <iostream>
using namespace std;
 

class Node
{
    public:
    int data;
    Node *next;
};
 

void push(Node ** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
 

void merge(Node *p, Node **q)
{
    Node *p_curr = p, *q_curr = *q;
    Node *p_next, *q_next;
 
    
    while (p_curr != NULL && q_curr != NULL)
    {
        
        p_next = p_curr->next;
        q_next = q_curr->next;
 
        
        q_curr->next = p_next; 
        p_curr->next = q_curr; 
 
        
        p_curr = p_next;
        q_curr = q_next;
    }
 
    *q = q_curr; 
}
 

int main()
{
    Node *p = NULL, *q = NULL;
    push(&p, 93);
    push(&p, 92);
    push(&p, 91);
    push(&p, 2);
    push(&p, 1);
    cout<<"First Linked List:\n";
    printList(p);
 
    push(&q, 96);
    push(&q, 95);
    push(&q, 94);
    push(&q, 4);
    push(&q, 3);
    cout<<"Second Linked List:\n";
    printList(q);
 
    merge(p, &q);
 
    cout<<"Final Linked List:\n";
    printList(p);
 
    return 0;
}