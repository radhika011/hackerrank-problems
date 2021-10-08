class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q){
        if(p!=NULL&&q==NULL) return false;
        if(p==NULL&&q!=NULL) return false;
        if(p==NULL&&q==NULL) return true;
        if(p->val==q->val) return helper(p->left,q->left)&&helper(p->right,q->right);
        else return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p,q);
    }
};
