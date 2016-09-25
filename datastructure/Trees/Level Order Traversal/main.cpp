#include<iostream>

using namespace std;




struct node
{
    int data;
    node* left;
    node* right;
};
#include<queue>
template<typename T>
void dispaly_LevelOrder(queue<T *>& tree_qu)
{
    if(tree_qu.empty())
        return;
    T* temp = tree_qu.front();
    tree_qu.pop();
    cout << temp->data << " ";
    if(temp->left)
        tree_qu.push(temp->left);
    if(temp->right)
        tree_qu.push(temp->right);
    
    dispaly_LevelOrder(tree_qu);
}

template<typename T>
void LevelOrder(T * root)
{
    if(root){
    queue<T *> level_order_qu;
    level_order_qu.push(root);
    dispaly_LevelOrder(level_order_qu);
    }
  
}

/********another solution**/
/*deque<Node*> treeQueue;

void levelOrder(Node* root){
    if( root ){
        treeQueue.push_back(root);
    }
    while( !treeQueue.empty() ){  
        Node* tree = treeQueue.front();
        treeQueue.pop_front();

        cout << tree->data << " ";

        if( tree->left ){
            treeQueue.push_back( tree->left );
        }
        if( tree->right ){
            treeQueue.push_back( tree->right );
        }
    }
}*/

int main()
{
    return 0;
}