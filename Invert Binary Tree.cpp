class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root!=NULL){
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        invertTree(root->right);
        invertTree(root->left);
        }
        return root;
        
    }
};
