#include<iostream>

using namespace std;
 
 
struct Node{

    int data;
    struct Node * next;

} *head;


void insertNode( struct Node **head, int data)
 {

    struct Node * newNode = new struct Node();
    newNode->data = data;
    newNode->next = *head;
    *head= newNode;

}

void displayIndex( struct Node *head1 )
    {
        struct Node *head2 =head1;
        while( head2 != nullptr){
            cout<< head2->data<< "->";
            head2 = head2->next;
        }
        cout<<"NULL";
    }

void Swap( struct Node* head1, int k)
    {
        int l = k;int count=0;
        struct Node* left=head1;
        struct Node* right=head1;
        struct Node* temp = head1;
        
        while( temp != nullptr){
            count++;
            temp = temp->next;
        }
        if( k < 0 || k> count ){
            cout<< "\ninvalid swapping!!!";
            return; 
        }

        for( int i = 1; i<=k-1;i++){
            left = left->next;

        }
            temp = head;
        for( int i = 0 ; i< count-k; i++)
            right = right->next;
        
        swap ( left->data, right->data);
        cout <<"\n Linked List after swapping : \n";
    displayIndex( temp);
    }

int main()
{
    head= nullptr;
    int size;
    cout<<"Enter NUmber of linked list you want : ";
    cin >> size;
    for(int i =size; i>0;i--)
    insertNode(&head, 100+i);
    int k;
    cout<<"\nEnter a Number to swap : ";
    cin >> k;
    cout <<"\n Linked List before swapping : \n";
    displayIndex( head);
    Swap(head,k);
    


return 0;
}