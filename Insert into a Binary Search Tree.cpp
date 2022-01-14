

/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.


*/


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ptr = root;
        TreeNode* parent = root;
        bool rightChild = false;
        TreeNode* newNode = new TreeNode(val);
        if(root==NULL){
            root = newNode;
            return root;
        }
        while(ptr!=NULL){
            int curr = ptr->val;
            parent = ptr;
            if(curr>val){
                ptr = ptr->left;
                rightChild = false;
            }
            else{
                ptr = ptr->right;
                rightChild = true;
            }
        }
        if(rightChild){
            parent->right = newNode;
        }
        else{
            parent->left = newNode;
        }
        return root;
    }
};
