
   struct Node {
      int data;
      Node* left;
      Node* right;
   };

bool check_if_left_SBT(Node* root,int data)
   {
       if(!root)
           return true;
       if(root->data >= data)
           return false;
       return check_if_left_SBT(root->left,data)&&check_if_left_SBT(root->right,data);
   }
   
   bool check_if_right_SBT(Node* root,int data)
   {
       if(!root)
           return true;
       if(root->data <= data)
           return false;
       return check_if_right_SBT(root->left,data)&&check_if_right_SBT(root->right,data);
   }
   
   bool checkBST(Node* root) {
       if(root)
       if(!(check_if_left_SBT(root->left,root->data)
       &&check_if_right_SBT(root->right,root->data)))
           return false;
       return !root?true:checkBST(root->left)&&checkBST(root->right);
       
   }
   
   
   int main()
   {
       
       return 0;
   }