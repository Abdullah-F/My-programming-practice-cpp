#include<iostream>
using namespace std;


struct node
{
    int data;
    node* left;
    node* right;
};

template<class T>
void preOrder(T *root) {
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    
}


int main()
{
    return 0;
}