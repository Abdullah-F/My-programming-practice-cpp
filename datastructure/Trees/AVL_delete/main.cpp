#include<iostream>
#include <algorithm>
using namespace std;

typedef struct node {

    node() {
        height = 0;
    }
    int data;
    int height;
    node * parent;
    node * left;
    node * right;
} node;

template<typename T>
T * insert(T * root, int value) {
    if (!root) {
        root = new T();
        root->data = value;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }

    if (value > root ->data) {
        if (!root->right) {
            root->right = new T();
            root->right->data = value;
            root->right->parent = root;
            root->right->left = nullptr;
            root->right->right = nullptr;
            return root; //returns the parent of the inserted node
        }
        insert(root->right, value); //just go right one more

    } else {
        if (!root->left) {
            root->left = new T();
            root->left->data = value;
            root->left->parent = root;
            root->left->right = nullptr;
            root->left->left = nullptr;
            return root; //return the parent of the new inserted node
        }
        insert(root->left, value); //go left one more
    }

}

node* find(node* root, int value) {// if not found it returns a pointer to the appropriate position where it can be inserted.
    if (root->data == value)
        return root;

    if (value > root->data && root->right)
        return find(root->right, value);
    else if (value < root->data && root->left) return find(root->left, value);

    return root;
}

template <class T>
void inOrder(T *root) {
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    cout << root->height << " ";
    inOrder(root->right);

}

node* left_descendant(node* right_node) {
    if (right_node->left)
        return left_descendant(right_node->left);
    return right_node;
}

node* right_ancestor(node* previous_node) {
    node* ancestor = previous_node->parent;

    while (ancestor && previous_node->data > ancestor->data)
        ancestor = ancestor->parent;

    return ancestor;
}

node* next(node* current) {// returns null if the number we search for is the largest one.

    if (current->right) {
        return left_descendant(current->right);
    } else {
        return right_ancestor(current);
    }

}

void rangeSearch(int min, int max, node* root) {

    node* next_node = find(root, min);
    while (next_node && next_node->data <= max && next_node->data >= min) {
        //we check always if the next value in the range
        cout << next_node->data << " ";
        next_node = next(next_node);
    }

}

void delete_node(node* node_to_be_deleted) {
    if (!node_to_be_deleted->right) {
        if (node_to_be_deleted->parent->left->data == node_to_be_deleted->data) {
            node_to_be_deleted->parent->left = node_to_be_deleted->left;
            if (node_to_be_deleted->left)
                node_to_be_deleted->left->parent = node_to_be_deleted->parent;
        } else {
            node_to_be_deleted->parent->right = node_to_be_deleted->left;
            if (node_to_be_deleted->left)
                node_to_be_deleted->left->parent = node_to_be_deleted->parent;
        }

    } else {
        node* next_node = next(node_to_be_deleted);
        node_to_be_deleted->data = next_node->data;
        delete_node(next_node);

    }
}


node* delete_node_avl_version(node* node_to_be_deleted) {
    if (!node_to_be_deleted->right) {
        if (node_to_be_deleted->parent->left->data == node_to_be_deleted->data) {
            node_to_be_deleted->parent->left = node_to_be_deleted->left;
            if (node_to_be_deleted->left)
                node_to_be_deleted->left->parent = node_to_be_deleted->parent;
        } else {
            node_to_be_deleted->parent->right = node_to_be_deleted->left;
            if (node_to_be_deleted->left)
                node_to_be_deleted->left->parent = node_to_be_deleted->parent;
        }
        
        return node_to_be_deleted->parent;
    } else {
        node* next_node = next(node_to_be_deleted);
        node_to_be_deleted->data = next_node->data;
        return delete_node_avl_version(next_node);

    }
}

void rotate_right(node(*(&root)), node *to_be_rotated) {
    if (!to_be_rotated)
        return;
    else if (!to_be_rotated->left)
        return;


    node* parent = to_be_rotated->parent;
    node* to_be_rotated_left = to_be_rotated->left;

    node* to_be_rotated_new_left = to_be_rotated->left->right;

    to_be_rotated_left->parent = parent;

    if (parent) {
        if (to_be_rotated_left->data >= parent->data)
            parent->right = to_be_rotated_left; //if to_be_rotated_left is "equal" or larger than parent
        else
            parent->left = to_be_rotated_left;
    } else root = to_be_rotated_left;

    to_be_rotated->parent = to_be_rotated_left;
    to_be_rotated_left->right = to_be_rotated;

    if (to_be_rotated_new_left)
        to_be_rotated_new_left->parent = to_be_rotated;

    to_be_rotated->left = to_be_rotated_new_left;

}

void rotate_left(node(*(&root)), node *to_be_rotated) {
    if (!to_be_rotated)
        return;
    else if (!to_be_rotated->right)
        return;

    node* parent = to_be_rotated->parent;
    node* to_be_rotated_right = to_be_rotated->right;
    node* to_be_rotated_new_right = to_be_rotated->right->left;

    to_be_rotated_right->parent = parent;

    if (parent) {
        if (to_be_rotated_right->data >= parent->data)
            parent->right = to_be_rotated_right;
        else parent->left = to_be_rotated_right;
    } else root = to_be_rotated_right;

    to_be_rotated->right = to_be_rotated_new_right;


    if (to_be_rotated_new_right)
        to_be_rotated_new_right->parent = to_be_rotated;

    to_be_rotated->parent = to_be_rotated_right;
    to_be_rotated_right->left = to_be_rotated;
}

void adjust_height(node* to_be_height_adjusted) {

    if (to_be_height_adjusted->left && to_be_height_adjusted->right)
        to_be_height_adjusted->height = 1 + max(to_be_height_adjusted->left->height,
            to_be_height_adjusted->right->height);
    else if (!to_be_height_adjusted->left && to_be_height_adjusted->right)
        to_be_height_adjusted->height = 1 + to_be_height_adjusted->right->height;
    else if (to_be_height_adjusted->left && !to_be_height_adjusted->right)
        to_be_height_adjusted->height = 1 + to_be_height_adjusted->left->height;
    else to_be_height_adjusted->height = 1;
}

void rebalance_left(node(*(&root)), node* node_to_be_balanced) {

    if (node_to_be_balanced->right) {
        node* node_to_be_balanced_right = node_to_be_balanced->right;

        if (node_to_be_balanced_right->right && node_to_be_balanced_right->left) {

            if (node_to_be_balanced_right->left->height >
                    node_to_be_balanced_right->right->height) {
                rotate_right(root, node_to_be_balanced_right);
                adjust_height(node_to_be_balanced_right);
                adjust_height(node_to_be_balanced_right->parent);
            }
        } else if (!node_to_be_balanced_right->right && node_to_be_balanced_right->left) {
            
                rotate_right(root, node_to_be_balanced);
                adjust_height(node_to_be_balanced_right);
                adjust_height(node_to_be_balanced_right->parent);
            
        }

    }

    rotate_left(root, node_to_be_balanced);
    adjust_height(node_to_be_balanced);
    adjust_height(node_to_be_balanced->parent);
}

void rebalance_right(node(*(&root)), node* node_to_be_balanced) {

    if (node_to_be_balanced->left) {

        node* node_to_be_balanced_left = node_to_be_balanced->left;
        if (node_to_be_balanced_left->right && node_to_be_balanced_left->left) {
            if (node_to_be_balanced_left->right->height >
                    node_to_be_balanced_left->left->height) {
                rotate_left(root, node_to_be_balanced_left);

                adjust_height(node_to_be_balanced_left);
                adjust_height(node_to_be_balanced_left->parent);
            }
        } else if (node_to_be_balanced_left->right && !node_to_be_balanced_left->left) {
            
            
                rotate_left(root, node_to_be_balanced_left);
                adjust_height(node_to_be_balanced_left);
                adjust_height(node_to_be_balanced_left->parent);
        }

    }

    rotate_right(root, node_to_be_balanced);
    adjust_height(node_to_be_balanced);
    adjust_height(node_to_be_balanced->parent);
}

void rebalance(node(*(&root)), node* balancing_starting_point) {
    node* parent = balancing_starting_point->parent;

    if (balancing_starting_point->left && balancing_starting_point->right) {
        if (balancing_starting_point->left->height >
                balancing_starting_point->right->height + 1)
            rebalance_right(root, balancing_starting_point);
    } else if (balancing_starting_point->left && !balancing_starting_point->right) {
        if (balancing_starting_point->left->height > 1)
            rebalance_right(root, balancing_starting_point);
    }

    if (balancing_starting_point->left && balancing_starting_point->right) {
        if (balancing_starting_point->right->height >
                balancing_starting_point->left->height + 1)
            rebalance_left(root, balancing_starting_point);
    } else if (!balancing_starting_point->left && balancing_starting_point->right) {
        if(balancing_starting_point->right->height > 1)
        rebalance_left(root, balancing_starting_point);
    }

    adjust_height(balancing_starting_point);
    
    if (parent)
        rebalance(root, parent);


}

node* insert_AVL(node(*(&root)), int value) {
    if (root)
        insert(root, value);
    else return insert(root, value);

    node* balance_starting_node = find(root, value);
    rebalance(root, balance_starting_node);
    return nullptr;
}

void delete_AVL(node(*(&root)), int value){
    if(root)
    {
        node* to_be_deleted = find(root, value);
        if(to_be_deleted->data = value){
        node* balance_starting_node = delete_node_avl_version(to_be_deleted);
        
        if(balance_starting_node)
        {
               rebalance(root, balance_starting_node);
        }
        
        }
        
    }
    
}

int main() {

    node* tree = nullptr;
    int size, value;

    cin >> size;
    cin >> value;

    tree = insert_AVL(tree, value);

    while (size > 1) {
        cin >> value;
        insert_AVL(tree, value);
        size--;
    }
    
   
    inOrder(tree);
    
    return 0;
}