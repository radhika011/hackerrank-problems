class Solution {
public:
    bool helper(TreeNode *a,TreeNode *b){
        if(a==NULL&&b==NULL){
            return true;
        }
        else if(a==NULL||b==NULL){
            return false;
        }
        else if(a->val!=b->val){
            return false;
        }
        return helper(a->right,b->left)&&helper(a->left,b->right);
    }
    bool isSymmetric(TreeNode* root) {
        bool ans = false;
        if(root!=NULL){
            ans = helper(root->left,root->right);
        }
        return ans;
    }
};
