#include<iostream>
using namespace std;




typedef struct node
{
   int data;
   node * left;
   node * right;
}node;



template<typename T>
T * insert(T * root, int value)
{
    if(!root)
    {
        root = new T();
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    
    if(value > root ->data)
    {
        if(!root->right){
            root->right = new T();
            root->right->data = value;
            root->right->left = nullptr;
            root->right->right = nullptr;
            return nullptr;
        }
        insert(root->right, value);
        
    }else{
        if(!root->left)
        {
            root->left = new T();
            root->left->data = value;
            root->left->right = nullptr;
            root->left->left = nullptr;
            return nullptr;
        }
        insert(root->left,value);
    }
    
    

   return root;
}


int main()
{
    
    return 0;
}