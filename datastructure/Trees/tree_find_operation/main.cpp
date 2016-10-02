#include<iostream>
#include <algorithm>
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

node* find(node* root,int value)
{
    if(root->data == value)
        return root;
    
    if(value > root->data && root->right)
        return find(root->right,value);
    else if(value < root->data && root->left) return find(root->left,value);
   
    return root;
}

template <class T> 
void inOrder(T *root) {
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

int main()
{
    
    node* tree = nullptr;
    int size, value;
    
    cin >> size;
    cin >> value;
    tree = insert(tree,value);
    while(size > 0){
        cin >> value;
        insert(tree,value);
        size--;
    }
   // inOrder(tree);
    cin >> value;
    cout << "you searched " << find(tree,value)->data << endl;
    
    return 0;
}