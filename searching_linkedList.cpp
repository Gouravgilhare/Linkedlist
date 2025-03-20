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

void displayIndex( struct Node *head1, int info){
    head = head1;int cnt=0;
    while( head != nullptr){
        cnt++;
        if( head->data == info) {    
            cout<<head->data;
            cout<< "\nYour Node is at "<<cnt<< "th index";
            return;
        }
        cout<<head->data<< "->";
        head =head->next;
    }

    cout <<"\nNot present";
    return; 
}




int main()
{
    head= nullptr;
    for(int i =0; i<10;i++)
    insertNode(&head, 100+i);
    cout<<"\nEter element YOu want to search : ";
    int n ;
    cin >> n;
    displayIndex( head,n) ;

return 0;
}