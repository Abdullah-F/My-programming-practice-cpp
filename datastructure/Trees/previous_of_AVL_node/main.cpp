#include<iostream>
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
T * insert(T * root, int value) {// note : "only inserts distinct values."
    if (!root) {
        root = new T();
        root->data = value;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
        return root;//returns the root
    }

    if (value >= root ->data) {
        if (!root->right) {
            root->right = new T();
            root->right->data = value;
            root->right->parent = root;
            root->right->left = nullptr;
            root->right->right = nullptr;
            return root; //returns the parent of the inserted node
        }
           
        return  insert(root->right, value); //just go right one more
    }   
       
        if (!root->left) {
            root->left = new T();
            root->left->data = value;
            root->left->parent = root;
            root->left->right = nullptr;
            root->left->left = nullptr;
            return root; //return the parent of the new inserted node
        }
    return insert(root->left, value); //go left one more
}

node* find(node* root, int value) {// if not found it returns a pointer to the appropriate position where it can be inserted.
    if (root->data == value)
        return root;

    if (value >= root->data && root->right)
        return find(root->right, value);
    else if (value < root->data && root->left) return find(root->left, value);

    return root;
}

node* left_descendant(node* right_node) {//used in the next function
    if (right_node->left)
        return left_descendant(right_node->left);
    return right_node;
}

node* right_ancestor(node* previous_node) {//used in the nex() function.
    node* ancestor = previous_node->parent;

    while (ancestor && previous_node->data >= ancestor->data)
        ancestor = ancestor->parent;

    return ancestor;
}


node* next_node_ptr(node* current) {// returns null if the number we search for is the largest one.

    if (current->right) {
        return left_descendant(current->right);
    } else {
        return right_ancestor(current);
    }

}

node* left_ancestor(node* previous_node) {//used in the nex() function.
    node* ancestor = previous_node->parent;

    while (ancestor && previous_node->data <= ancestor->data)
        ancestor = ancestor->parent;

    return ancestor;
}

node* right_descendant(node* left_node) {//used in the next function
    if (left_node->right)
        return right_descendant(left_node->right);
    return left_node;
}

node* previous_node_ptr(node* current) {
if (current->left) {
        return right_descendant(current->left);
    } else {
        return left_ancestor(current);
    }

}


template <class T>
void inOrder(T *root) {
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    cout << root->height << " " << endl;
    inOrder(root->right);

}


void rangeSearch(int min, int max, node* root) {

    node* next_node = find(root, min);
    while (next_node && next_node->data <= max && next_node->data >= min) {
        //we check always if the next value in the range
        cout << next_node->data << " ";
        next_node = next_node_ptr(next_node);
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
        node* next_node = next_node_ptr(node_to_be_deleted);
        node_to_be_deleted->data = next_node->data;
        delete_node(next_node);

    }
}



node* delete_node_avl_version(node(*(&root)),node* node_to_be_deleted) {//works fine whiout errors, but needs more
    //testing
    if (!node_to_be_deleted->right) {
        
        if(node_to_be_deleted->parent){
            
        if (node_to_be_deleted->parent->left&&
                (node_to_be_deleted->parent->left->data == 
                node_to_be_deleted->data)) {
            
            node_to_be_deleted->parent->left = node_to_be_deleted->left;
            if (node_to_be_deleted->left)
                node_to_be_deleted->left->parent = node_to_be_deleted->parent;
        } else {
            node_to_be_deleted->parent->right = node_to_be_deleted->left;
            if (node_to_be_deleted->left)
                node_to_be_deleted->left->parent = node_to_be_deleted->parent;
        }
        
        }else if(!node_to_be_deleted->parent && node_to_be_deleted->left)
        {
            root = node_to_be_deleted->left;
            return nullptr;// return the parent of the deleted node
        }
        else if(!node_to_be_deleted->parent && !node_to_be_deleted->left)
            return nullptr;//returns the parent of the deleted node
        
        return node_to_be_deleted->parent;//returns the parent of the deleted node

    } else {
        node* next_node = next_node_ptr(node_to_be_deleted);//find next element to be deleted
        node_to_be_deleted->data = next_node->data;//replace the deleted node with its next
        //the above line is doing replacements each time. to better make it only once. 
       return  delete_node_avl_version(root,next_node);//delete next value (since it is now duplicate value.).

    }
}


void rotate_right(node(*(&root)), node *to_be_rotated) {//well tested.
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

void rotate_left(node(*(&root)), node *to_be_rotated) {//well tested
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

void adjust_height(node* to_be_height_adjusted) {//well tested

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
            
                rotate_right(root, node_to_be_balanced_right);
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
    //well tested function.
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

    adjust_height(balancing_starting_point);// to be better but it in an else statement after the above conditions.
    
    if (parent)
        rebalance(root, parent);


}

void insert_AVL(node(*(&root)), int value) {
    node* balance_starting_node;
    if (root){
     balance_starting_node = insert(root, value);
    if(value >= balance_starting_node->data)
        balance_starting_node = balance_starting_node->right;
    else 
        balance_starting_node = balance_starting_node->left;
    }
    else{
        
     root =  insert(root, value);// if tree is empty create a head .
     balance_starting_node = root;
    }
    
    rebalance(root, balance_starting_node);
}



void delete_AVL(node(*(&root)), int value)
{//produces correct outputs , still needs further testing
 //only works on distinct values input, needs small adjustment for none-distinct values.
    if(root)
    {
        node* node_to_be_deleted = find(root,value);
        if(node_to_be_deleted->data == value)
        {
            node* balance_starting_point = delete_node_avl_version(root,node_to_be_deleted);
            if(balance_starting_point){
                rebalance(root,balance_starting_point);
            }else return;
            
        }else return;
    }else return;
}


int main() {

    node* tree = nullptr;
    int size, value;

    cin >> size;
    
    while (size > 0) {
        cin >> value;
        insert_AVL(tree, value);
        size--;
    }

    inOrder(tree);
    cout << "root  :  " << tree->data << endl;
    
    
    cout << "previous  :  " << previous_node_ptr(find(tree,1))->data << endl;
    return 0;
}