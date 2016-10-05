#include<iostream>
#include <algorithm>
using namespace std;




typedef struct node
{
   int data;
   node * parent;
   node * left;
   node * right;
}node;



template<typename T>
T * insert(T * root, int value)
{
    if(!root)
    {
        root = new T();
        root->data   = value;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    
    if(value > root ->data)
    {
        if(!root->right){
            root->right = new T();
            root->right->data = value;
            root->right->parent = root;
            root->right->left = nullptr;
            root->right->right = nullptr;
            return root;//returns the parent of the inserted node
        }
        insert(root->right, value);//just go right one more
        
    }else{
        if(!root->left)
        {
            root->left = new T();
            root->left->data = value;
            root->left->parent = root;
            root->left->right = nullptr;
            root->left->left = nullptr;
            return root; //return the parent of the new inserted node
        }
        insert(root->left,value);//go left one more
    }
   
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

node* left_descendant(node* right_node)
{
    if(right_node->left)
      return  left_descendant(right_node->left);
    return right_node;
}

node* right_ancestor(node* previous_node)
{
    node* ancestor = previous_node->parent;
    
        while (ancestor && previous_node->data > ancestor->data)
            ancestor = ancestor->parent;
    
    return ancestor;
}


node* next(node* current)
{// returns null if the number we search for is the largest one.
    
    if(current->right)
    {
     return left_descendant(current->right);   
    }else{
     return right_ancestor(current);
    }
 
}

void rangeSearch(int min , int max , node* root)
{
    
    node* next_node = find(root,min);
    while (next_node && next_node->data <= max && next_node->data >= min){
        //we check always if the next value in the range
        cout << next_node->data << " ";
        next_node = next(next_node);
    }

}

void delete_node(node* node_to_be_deleted)
{
    if(!node_to_be_deleted->right)
    {
     if(node_to_be_deleted->parent->left->data == node_to_be_deleted->data)
     {
       node_to_be_deleted->parent->left = node_to_be_deleted->left;
       if(node_to_be_deleted->left)
           node_to_be_deleted->left->parent = node_to_be_deleted->parent;
     }else{
         node_to_be_deleted->parent->right = node_to_be_deleted->left;
         if(node_to_be_deleted->left)
             node_to_be_deleted->left->parent = node_to_be_deleted->parent;
     }
     
    }else{
        node* next_node = next(node_to_be_deleted);
        node_to_be_deleted->data = next_node->data;
        delete_node(next_node);   
        
    }
    
        
    
}


void rotate_right(node (*(&root)) , node *to_be_rotated)
{ 
    if(!to_be_rotated)
        return;
    else if(!to_be_rotated->left)
        return;
    
    
    node* parent = to_be_rotated->parent;
    node* to_be_rotated_left = to_be_rotated->left;
    
    node* to_be_rotated_new_left = to_be_rotated->left->right;
    
    to_be_rotated_left->parent = parent;
    
    if(parent){
    if(to_be_rotated_left->data >= parent->data)
        parent->right = to_be_rotated_left;//if to_be_rotated_left is "equal" or larger than parent
    else
        parent->left = to_be_rotated_left;
    }else root = to_be_rotated_left;
  
    to_be_rotated->parent = to_be_rotated_left;
    to_be_rotated_left->right = to_be_rotated;
    
    if(to_be_rotated_new_left)
    to_be_rotated_new_left->parent = to_be_rotated;
    
    to_be_rotated->left = to_be_rotated_new_left;
   
}


int main()
{
    
    node* tree = nullptr;
    int size, value;
    
    cin >> size;
    cin >> value;
    tree = insert(tree,value);
    while(size > 1){
        cin >> value;
        insert(tree,value);
        size--;
    }
    cin >> value;
    
    inOrder(tree);
    cout << endl;    
    rotate_right(tree,find(tree,value));
    inOrder(tree);
    return 0;
}