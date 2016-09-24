#include<iostream>
using namespace std;


struct node
{
    int data;
    node* left;
    node* right;
};

template<typename T>
void printLeft(T * root)
{
    if(!root)
        return;
    
    printLeft(root->left);   
    cout << root->data << " ";
}

template<typename T>
void printRight(T * root)
{
    if(!root)
        return;
    
    printRight(root->right);   
    cout << root->data << " ";
}

template<typename T>
void top_view(T * root)
{
    if(!root)
        return ;
    
    printLeft(root->left);
    printRight(root->right);
    cout << root->data << " ";
    
  
}
int main()
{
    
    return 0;
    
}