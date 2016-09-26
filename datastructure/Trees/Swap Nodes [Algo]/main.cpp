#include <iostream>
#include<queue>
using namespace std;

struct Node {

    Node(int data, Node* left, Node* right,int depth) {
        this->data = data;
        this->left = left;
        this->right = right;
        this->depth = depth;
    }
    
    int depth;
    int data;
    Node* left;
    Node* right;
};



template <class T> 
void inOrder(T *root) {
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}


Node* fill_tree_in_level_order(int number_of_nodes) {
    Node* root = new Node(1, nullptr, nullptr,1), *temp;
    queue<Node*> level;
    level.push(root);
    int left_data, right_data;

    while (number_of_nodes > 0) {
        cin >> left_data >> right_data;
        temp = level.front();

        if (left_data == -1)
            temp->left = nullptr;
        else {
            temp->left = new Node(left_data, nullptr, nullptr,temp->depth+1);
            level.push(temp->left);
        }

        if (right_data == -1)
            temp->right = nullptr;
        else {
            temp->right = new Node(right_data, nullptr, nullptr,temp->depth+1);
            level.push(temp->right);
        }
        level.pop();
        number_of_nodes--;

    }


    return root;
}

 void tree_swap(Node* root,int k){
    
    if(!root)
        return;
   
    if( root->depth%k == 0 )
    {    
        Node* temp = root->right;
        root->right = root->left;
        root->left = temp;
     }
    
    tree_swap(root->left , k);
    tree_swap(root->right, k);
    
     
    
}

int main() {
    int number_of_nodes, number_of_swaps,k;
    
    cin >> number_of_nodes ;
    Node* root = fill_tree_in_level_order(number_of_nodes);
    cin >> number_of_swaps;

    while(number_of_swaps > 0)
    {
        cin >> k;
        tree_swap(root,k);
        inOrder(root);
        cout << endl;
        number_of_swaps--;
    }
    
    return 0;
}
