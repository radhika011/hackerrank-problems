class Solution {
public:
    TreeNode* lca(TreeNode* localRoot, TreeNode* p,TreeNode* q){
        if(localRoot==NULL) return NULL;
        if(localRoot->val==p->val||localRoot->val==q->val) return localRoot;
        else if(localRoot->val<p->val&&localRoot->val<q->val){
           if(localRoot->right!=NULL) return lca(localRoot->right,p,q);
        }
        else if(localRoot->val>p->val&&localRoot->val>q->val){
            if(localRoot->left!=NULL) return lca(localRoot->left,p,q);
        }
        return localRoot;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        ans = lca(root,p,q);
        return ans;
    }
};
