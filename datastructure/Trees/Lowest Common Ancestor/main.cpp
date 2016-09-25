#include<iostream>
using namespace std;


typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

// this code is based on the assumption  that v1 , v2 surly exist in the tree.
template<typename T>
T*  lca (T* root ,int v1,int v2)
{
    T *ptr1 = root , *ptr2 = root , *ancentor = nullptr;
    
    while(ptr1 && ptr2)
    {
        if(ptr1 == ptr2){
            ancentor = ptr1;
        }
        
        if(ptr1->data == v1 || ptr2->data == v2)
            break;
        if(v1 > ptr1->data)
            ptr1 = ptr1->right;
        else ptr1 = ptr1->left;
        
        if(v2 > ptr2->data)
            ptr2 = ptr2->right;
        else ptr2 = ptr2->left;
        
      
    }
    
    return ancentor;
}

int main()
{
    
    return 0;
}