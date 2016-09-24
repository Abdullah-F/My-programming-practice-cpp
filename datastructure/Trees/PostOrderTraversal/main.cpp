#include<iostream>
using namespace std;


struct node
{
    int data;
    node* left;
    node* right;
};


template<class T>
void postOrder(T *root) {
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}



int main()
{
    return 0;
}