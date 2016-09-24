#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

template<typename T>
int height(T* root)
{
 if(!root)
     return -1;
 
 int height1 = height(root->left);
 int height2 = height(root->right);
 
 return (height1 > height2 ? height1+1:height2+1);
}

int main()
{
    return 0;
}