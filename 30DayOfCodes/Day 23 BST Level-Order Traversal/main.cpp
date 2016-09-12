#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

class Solution {
public:

    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    void levelOrder(Node * root) {

        queue<Node*> level_queue;
        Node* current_node;

        if (root != nullptr) {
            level_queue.push(root);
            while (!level_queue.empty()) {
                current_node = level_queue.front();
                level_queue.pop();
                cout << current_node->data << " ";

                if (current_node->left)
                    level_queue.push(current_node->left);


                if (current_node->right)
                    level_queue.push(current_node->right);
            }

        }


    }


}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int T, data;
    cin>>T;
    while (T-- > 0) {
        cin>>data;
        root = myTree.insert(root, data);
    }
    myTree.levelOrder(root);
    return 0;
} 