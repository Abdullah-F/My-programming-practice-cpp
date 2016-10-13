/*
 * C++ program to Implement AVL Tree
 */
#include<iostream>
using namespace std;

/*
 * Node Declaration
 */

struct node {

    node() {
        height = 0;
        tree_size = 0;
    }

    int tree_size;
    long int data;
    int height;
    node * parent;
    node * left;
    node * right;
};

/*
 * Class Declaration
 */
class AvlTree {
private:
    node *tree_root;
    node *add_node(node* parent,int value){
            node* new_node = new node();
            new_node->data = value;
            new_node->parent = parent;
            new_node->left = nullptr;
            new_node->right = nullptr;
            return new_node;
    };
    
     void adjust_height(node* to_be_height_adjusted) {//well tested

        if (to_be_height_adjusted->left && to_be_height_adjusted->right) {
            to_be_height_adjusted->height = 1 + max(to_be_height_adjusted->left->height,
                    to_be_height_adjusted->right->height); //adjust height

            to_be_height_adjusted->tree_size = 1 + to_be_height_adjusted->left->tree_size +
                    to_be_height_adjusted->right->tree_size; //adjust size
        } else if (!to_be_height_adjusted->left && to_be_height_adjusted->right) {
            to_be_height_adjusted->height = 1 + to_be_height_adjusted->right->height; //adjust height 
            to_be_height_adjusted->tree_size = to_be_height_adjusted->height; //adjust size
        } else if (to_be_height_adjusted->left && !to_be_height_adjusted->right) {
            to_be_height_adjusted->height = 1 + to_be_height_adjusted->left->height; //adjust height
            to_be_height_adjusted->tree_size = to_be_height_adjusted->height; //adjust size
        } else {
            to_be_height_adjusted->height = 1; //set height = 1
            to_be_height_adjusted->tree_size = to_be_height_adjusted->height; //adjust size
        }
    }

public:

    AvlTree() {
        tree_root = nullptr;
    }

    node *get_root() {
        return tree_root;
    }
    
    int get_tree_size()
    {
        if(tree_root)
            return tree_root->tree_size;
        return -1;
        
    }
    
    void insert(node * root, int value) {
        if (!root) {
            tree_root = add_node(nullptr,value);
            rebalance(tree_root);
            return;
        } else if (value >= root ->data) {
            if (!root->right) {
                root->right = add_node(root,value);
                rebalance(root->right);
            } else
                insert(root->right, value); //just go right one more

        } else {

            if (!root->left) {
                root->left = add_node(root,value);
                rebalance(root->left);
            } else
                insert(root->left, value); //go left one more
        }
        rebalance(root);
    }

    node* find(node* root, int value) {
        // if not found it returns a pointer to the appropriate position where it can be inserted.
        if (!root)
            return root;
        if (root->data == value)
            return root;

        if (value >= root->data && root->right)
            return find(root->right, value);
        else if (value < root->data && root->left) 
            return find(root->left, value);

        return root;
    }

    void rotate_right(node *to_be_rotated) {//well tested.
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
        } else tree_root = to_be_rotated_left;

        to_be_rotated->parent = to_be_rotated_left;
        to_be_rotated_left->right = to_be_rotated;

        if (to_be_rotated_new_left)
            to_be_rotated_new_left->parent = to_be_rotated;

        to_be_rotated->left = to_be_rotated_new_left;

    }

    void rotate_left(node *to_be_rotated) {//well tested
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
        } else tree_root = to_be_rotated_right;

        to_be_rotated->right = to_be_rotated_new_right;


        if (to_be_rotated_new_right)
            to_be_rotated_new_right->parent = to_be_rotated;

        to_be_rotated->parent = to_be_rotated_right;
        to_be_rotated_right->left = to_be_rotated;
    }

   

    void rebalance_left(node* node_to_be_balanced) {

        if (node_to_be_balanced->right) {
            node* node_to_be_balanced_right = node_to_be_balanced->right;

            if (node_to_be_balanced_right->right && node_to_be_balanced_right->left) {

                if (node_to_be_balanced_right->left->height >
                        node_to_be_balanced_right->right->height) {
                    rotate_right(node_to_be_balanced_right);
                    adjust_height(node_to_be_balanced_right);
                    adjust_height(node_to_be_balanced_right->parent);
                }
            } else if (!node_to_be_balanced_right->right && node_to_be_balanced_right->left) {

                rotate_right(node_to_be_balanced_right);
                adjust_height(node_to_be_balanced_right);
                adjust_height(node_to_be_balanced_right->parent);

            }

        }

        rotate_left(node_to_be_balanced);
        adjust_height(node_to_be_balanced);
        adjust_height(node_to_be_balanced->parent);
    }

    void rebalance_right(node* node_to_be_balanced) {

        if (node_to_be_balanced->left) {

            node* node_to_be_balanced_left = node_to_be_balanced->left;
            if (node_to_be_balanced_left->right && node_to_be_balanced_left->left) {
                if (node_to_be_balanced_left->right->height >
                        node_to_be_balanced_left->left->height) {
                    rotate_left(node_to_be_balanced_left);

                    adjust_height(node_to_be_balanced_left);
                    adjust_height(node_to_be_balanced_left->parent);
                }
            } else if (node_to_be_balanced_left->right && !node_to_be_balanced_left->left) {


                rotate_left(node_to_be_balanced_left);
                adjust_height(node_to_be_balanced_left);
                adjust_height(node_to_be_balanced_left->parent);
            }

        }

        rotate_right(node_to_be_balanced);
        adjust_height(node_to_be_balanced);
        adjust_height(node_to_be_balanced->parent);
    }

    void rebalance(node* node_to_be_balanced) {

        //well tested function.
        if (node_to_be_balanced->left && node_to_be_balanced->right) {
            if (node_to_be_balanced->left->height >
                    node_to_be_balanced->right->height + 1)
                rebalance_right(node_to_be_balanced);
        } else if (node_to_be_balanced->left && !node_to_be_balanced->right) {
            if (node_to_be_balanced->left->height > 1)
                rebalance_right(node_to_be_balanced);
        }

        if (node_to_be_balanced->left && node_to_be_balanced->right) {
            if (node_to_be_balanced->right->height >
                    node_to_be_balanced->left->height + 1)
                rebalance_left(node_to_be_balanced);
        } else if (!node_to_be_balanced->left && node_to_be_balanced->right) {
            if (node_to_be_balanced->right->height > 1)
                rebalance_left(node_to_be_balanced);
        }

        adjust_height(node_to_be_balanced); // to be better but it in an else statement after the above conditions.

    }

    void inOrder(node *root) {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        cout << root->height << " " << endl;
        inOrder(root->right);

    }

};

int main() {
    AvlTree tree;
    int size, value;
    cin >> size;
    while (size > 0) {
        cin >> value;
        tree.insert(tree.get_root(), value);
        size--;
    }

    tree.inOrder(tree.get_root());
    cout << "tree size : " << tree.get_tree_size() << endl;
    return 0;
}