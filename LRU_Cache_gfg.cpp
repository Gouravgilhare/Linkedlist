#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 


class Node{

    
    public: 
    
    int key,value;
    Node* next;
    Node* prev;
    
    Node( int key , int value){
        this->key = key;
        this->value= value;
        prev= nullptr;
        next= nullptr;
    }
};


class LRUCache {
  private:
  unordered_map<int, Node*> mpp;
  Node*head,*tail;
  int capacity;
  public:
  
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
    
        capacity = cap;
        mpp.clear();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        
        if( mpp.find(key) == mpp.end()) 
        return -1;
        
        Node * node = mpp[key];
        deleteNode( node);
        insertAfterHead(node);
        
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            
            Node * node =mpp[key];
            node->value= value;
            movetohead(node);
            
        }
        else{
            if(mpp.size() >= capacity){
                Node* lruNode= tail->prev;
                mpp.erase(lruNode->key);
                deleteNode(lruNode);
                delete lruNode;
            }
            
            Node* node = new Node( key, value);
            mpp[key] =node;
            insertAfterHead(node);
            
        }
        
        // your code here
    }
    
    void deleteNode( Node* node){
     
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAfterHead( Node * node){
        
        Node* currAfterHead= head->next;
        head->next = node;
        node->next =currAfterHead;
        node->prev = head;
        currAfterHead->prev = node;
        
    }
    void movetohead( Node* node){
        deleteNode(node);
        insertAfterHead(node);
    }
    
};

int main(){

    int t;
    cin >> t;
    while(t--){

        int capacity;
        cin >> capacity;
        LRUCache * cache = new LRUCache( capacity);

        int queries;
        cin >> queries;
        while(queries--){

            string q;
            cin >> q;
            if(q == "PUT"){
                int key; cin >> key;
                int value; cin >> value;
                cache->put( key,value);

            }else{
                int key;
                cin>> key;
                cout << cache->get(key)<< " " ;

            }

        }
        cout << endl;
        cout<< " ~" <<endl;
    }
    return 0;
    

}