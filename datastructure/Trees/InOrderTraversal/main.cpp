#include<iostream>
using namespace std;


struct node
{
    int data;
    node* left;
    node* right;
};


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
    
    return 0;
}