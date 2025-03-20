#include<iostream>
using namespace std;
 
struct Node{
    int data ;
    struct Node *next;
};

void insertNode( struct Node **head, int data)
 {

    struct Node * newNode = new struct Node();
    newNode->data = data;
    newNode->next = *head;
    *head= newNode;

 }

 void insertEnd(struct Node **head, int data){

    struct Node * newNode = new struct Node();
    struct Node * temp = *head;
    newNode->data= data;
    while(temp->next != nullptr){
        temp= temp->next;
    }
    temp->next = newNode;
    newNode->next= nullptr;
 }
 void insertMid( struct Node**head, int k ,int data ){
    struct Node *temp = *head;
    struct Node *newNode = new struct Node();
    newNode->data = data;

    while( k>0){
        temp= temp->next;
    }
    newNode->next= temp->next;
    temp->next = newNode;
   
    return;
 }
 void display(struct Node *head){

    struct Node * temp= head;
    while( temp != nullptr){
        cout<< temp->data<<"->";
        temp= temp->next;
    }
 }
int main()
{
    struct Node *head=NULL;
    
    insertNode(&head, 30);
    insertNode(&head, 20);
    insertNode(&head, 10);

    insertEnd(&head, 40);
    insertEnd(&head,50);
    insertEnd(&head, 60);


    insertMid(&head, 5, 70);
    display(head);


return 0;
}