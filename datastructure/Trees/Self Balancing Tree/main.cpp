#include<iostream>
using namespace std;

typedef struct node {
    int val;// here in this code we assume that (ht) starts at zero.
    struct node* left;
    struct node* right;
    int ht;
} node;

template<typename T>
T * insert_node(T * root, int value) {
    if (!root) {
        root = new T();
        root->val = value;
        root->ht = 0;
        root->left = nullptr;
        root->right = nullptr;
        return root; //returns the created root
    }
 
    if (value > root ->val) {
        if (!root->right) {
            root->right = new T();
            root->right->val = value;
            root->right->ht = 0;
            root->right->left = nullptr;
            root->right->right = nullptr;
            return root->right;//returns the created node
        }
        return insert_node(root->right, value);
    }

    if (!root->left) {
        root->left = new T();
        root->left->val = value;
        root->left->ht = 0;
        root->left->right = nullptr;
        root->left->left = nullptr;
        return root->left;//returns the created node
    }
    return insert_node(root->left, value);

}

node* find_parent(node* root, int value) {
    if (root->left && root->left->val == value)
        return root; //return current node as parent
    else if (root->right && root->right->val == value)
        return root; //return current node as parent
    else if (root->val == value)
        return nullptr; //returns root parent


    if (root->right && value > root->val)
        return find_parent(root->right, value);
    else if (root->left && value < root->val)
        return find_parent(root->left, value);
    return nullptr;//node not found, so no parent
}

void adjust_height(node* to_be_height_adjusted) {//well tested

    if (to_be_height_adjusted->left && to_be_height_adjusted->right)
        to_be_height_adjusted->ht = 1 + max(to_be_height_adjusted->left->ht,
            to_be_height_adjusted->right->ht);
    else if (!to_be_height_adjusted->left && to_be_height_adjusted->right)
        to_be_height_adjusted->ht = 1 + to_be_height_adjusted->right->ht;
    else if (to_be_height_adjusted->left && !to_be_height_adjusted->right)
        to_be_height_adjusted->ht = 1 + to_be_height_adjusted->left->ht;
    else to_be_height_adjusted->ht = 0;
}

node* rotate_right(node *(&root), node* node_to_be_rotated) {

    if (!node_to_be_rotated)
        return nullptr;

    if (!node_to_be_rotated->left)
        return nullptr;

    node* parent = find_parent(root, node_to_be_rotated->val);
    node* node_to_be_rotated_left = node_to_be_rotated->left;

    if (parent) {
        if (parent->left == node_to_be_rotated)
            parent->left = node_to_be_rotated->left;
        else parent->right = node_to_be_rotated->left;

        node_to_be_rotated->left = node_to_be_rotated->left->right;
        node_to_be_rotated_left->right = node_to_be_rotated;
    } else {
        node_to_be_rotated->left = node_to_be_rotated->left->right;
        node_to_be_rotated_left->right = node_to_be_rotated;
        root = node_to_be_rotated_left;
    }
    return node_to_be_rotated_left;
}

node* rotate_left(node *(&root), node* node_to_be_rotated) {
    if (!node_to_be_rotated)
        return nullptr;

    if (!node_to_be_rotated->right)
        return nullptr;

    node* parent = find_parent(root, node_to_be_rotated->val);
    node* node_to_be_rotated_right = node_to_be_rotated->right;
    if (parent) {
        if (parent->left == node_to_be_rotated)
            parent->left = node_to_be_rotated->right;
        else
            parent->right = node_to_be_rotated->right;

        node_to_be_rotated->right = node_to_be_rotated->right->left;
        node_to_be_rotated_right->left = node_to_be_rotated;
    } else {
        node_to_be_rotated->right = node_to_be_rotated->right->left;
        node_to_be_rotated_right->left = node_to_be_rotated;
        root = node_to_be_rotated_right;
    }

    return node_to_be_rotated_right;
}

void balance_left(node *(&root), node* node_to_be_balanced) {
    if (!node_to_be_balanced)
        return;
    node* node_to_be_balanced_right =
            node_to_be_balanced->right;

    if (node_to_be_balanced_right)
        if (node_to_be_balanced_right->left && node_to_be_balanced_right->right){
            if (node_to_be_balanced_right->left->ht >
                    node_to_be_balanced_right->right->ht)
            {
                node* node_to_be_balanced_right_previous_left =
                        rotate_right(root,node_to_be_balanced_right);
                adjust_height(node_to_be_balanced_right);
                adjust_height(node_to_be_balanced_right_previous_left);
            }
            
              }else if(node_to_be_balanced_right->left && !node_to_be_balanced_right->right)
              {
                  node* node_to_be_balanced_right_previous_left =
                        rotate_right(root,node_to_be_balanced_right);
                  
                adjust_height(node_to_be_balanced_right);
                adjust_height(node_to_be_balanced_right_previous_left);
              }
    
            node* node_to_be_balanced_previous_right = 
                    rotate_left(root,node_to_be_balanced);
            
             adjust_height(node_to_be_balanced); 
             adjust_height(node_to_be_balanced_previous_right);
                         
            
}

void balance_right(node *(&root), node* node_to_be_balanced){
    if(!node_to_be_balanced)
        return;
    node* node_to_be_balanced_left =
            node_to_be_balanced->left;
    
    if (node_to_be_balanced_left)
    if (node_to_be_balanced_left->right && node_to_be_balanced_left->left){
            if (node_to_be_balanced_left->right->ht >
                    node_to_be_balanced_left->left->ht)
            {
                node* node_to_be_balanced_left_previous_right =
                        rotate_left(root,node_to_be_balanced_left);
                adjust_height(node_to_be_balanced_left);
                adjust_height(node_to_be_balanced_left_previous_right);
            }
            
              }else if(node_to_be_balanced_left->right && !node_to_be_balanced_left->left)
              {
                  node* node_to_be_balanced_left_previous_right =
                        rotate_left(root,node_to_be_balanced_left);
                  
                adjust_height(node_to_be_balanced_left);
                adjust_height(node_to_be_balanced_left_previous_right);
              }
    
     node* node_to_be_balanced_previous_left = 
                    rotate_right(root,node_to_be_balanced);
            
             adjust_height(node_to_be_balanced); 
             adjust_height(node_to_be_balanced_previous_left);

}

void balance(node *(&root), node* balancing_start_node)
{
    
    
    if(balancing_start_node->left && balancing_start_node->right){
        if(balancing_start_node->left->ht > balancing_start_node->right->ht+1)
            balance_right(root,balancing_start_node);
        else if(balancing_start_node->left->ht+1 < balancing_start_node->right->ht)
            balance_left(root,balancing_start_node);
    }else if(balancing_start_node->left &&
            balancing_start_node->left->ht > 0 && !balancing_start_node->right)
        balance_right(root,balancing_start_node);
    else if(!balancing_start_node->left && balancing_start_node->right &&
            balancing_start_node->right->ht > 0)
        balance_left(root,balancing_start_node);
      adjust_height(balancing_start_node);
    
    node* parent = find_parent(root,balancing_start_node->val);
    if(parent)
        balance(root,parent);
}

template <class T>
void inOrder(T *root) {
    int op1 = -1 , op2 = -1;
    if (!root)
        return;
    inOrder(root->left);
    cout << root->val << "  (BF = ";
    if(root->left)
        op1 = root->left->ht;
    
    if(root->right)
        op2 = root->right->ht;
    cout << op1-op2 <<  " ) "  << "height : " << root->ht << "  " << op1 << " - " << op2 << " " << endl;
    inOrder(root->right);

}


node * insert(node * (root),int val)
{
    
    node* inserted_node;
    if(root)
        inserted_node = insert_node(root,val);
    else {
        root = insert_node(root,val);
        inserted_node = root;
    }
    balance(root,inserted_node);
    
    return root;
}

int main() {
    int size;
    int value;

    cin >> size;
    node* tree = nullptr;

    while (size > 0) {
        cin >> value;
        insert(tree, value);
        size--;
    }
    
    
    inOrder(tree);
    
    return 0;
}