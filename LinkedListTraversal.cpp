#include<iostream>
#include<stdlib.h> //for linked list
using namespace std;
 
struct Node{
    int data ;
    struct Node *next;
};


void insertNode( struct Node **head, int data)
 {
    if(head  == nullptr ) return ;

    struct Node * newNode = new struct Node();
    if( newNode == nullptr) 
    {
        cout << "NOde not created "; return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head= newNode;

 }


 void display(struct Node *head){

    struct Node * temp= head;
    int count  = 0;
    while( temp != nullptr){
        cout<< temp->data<<"->";
        count++;
        temp= temp->next;
    }

    cout<< "\nTotal COunt : "<<count;
 }
int main()
{
    struct Node *head=NULL;
    
    insertNode(&head, 50);
    insertNode(&head, 40);
    insertNode(&head, 30);
    insertNode(&head, 20);
    insertNode(&head, 10);

    display(head);


return 0;
}