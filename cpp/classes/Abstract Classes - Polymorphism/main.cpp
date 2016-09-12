#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

#define get_pair(key,node) pair<int,Node*>(key,node)
struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache:public Cache{
    
public:
    LRUCache(int capacity)
    {
        cp = capacity;
    }
    
    void set(int key , int value){
        if(cp < 1 ) return;
        Node* node_to_be_inserted = new Node(key,value);
        
        if(mp.size() == 0)
        {   
            insert_into_head(node_to_be_inserted);
            mp.insert(get_pair(key,node_to_be_inserted));
        
        }else if(mp.find(key) != mp.end())
        {
             
            mp[key]->value = value;
            insert_into_head(mp[key]);
            
        }else if(mp.size() < cp)
        {
            insert_into_head(node_to_be_inserted);
            mp.insert(get_pair(key,node_to_be_inserted));
        }else
        {
            mp.erase(tail->key);
            delete_node(tail);
            insert_into_head(node_to_be_inserted);
            mp.insert(get_pair(key,node_to_be_inserted));
        }
    }
    
    int get(int key)
    {
        if(cp < 1)return -1;
        if(mp.find(key) != mp.end())
            {
            insert_into_head(mp[key]);
            return mp[key]->value;
        }
        return -1;
    }
 
private:
    void delete_node(Node* to_be_deleted_node)
    {
        if(to_be_deleted_node->prev)
            to_be_deleted_node->prev->next = to_be_deleted_node->next;
        if(to_be_deleted_node->next)
            to_be_deleted_node->next->prev = to_be_deleted_node->prev;
        
        if(!to_be_deleted_node->prev)
        {
            head = to_be_deleted_node->next;
            if(head)
            head->prev = nullptr;
        }
        
        
        if(!to_be_deleted_node->next)
        {
            tail = to_be_deleted_node->prev;
            if(tail)
                tail->next = nullptr;
        }
    }
    
    void insert_into_head(Node* node_to_be_inserted)
    {
        if(!node_to_be_inserted)
            return;
        
        delete_node(node_to_be_inserted);
        
        node_to_be_inserted->next = head;
        
        if(head)
        {
            head->prev =node_to_be_inserted;
            node_to_be_inserted->prev = nullptr;
        }
        
        head = node_to_be_inserted;
        
        if(!tail)
        {
            tail = node_to_be_inserted;
            tail->next = nullptr;
        
        }
        
        
    }

};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
