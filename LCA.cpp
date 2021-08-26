class Solution {
public:
    bool isPresent(TreeNode* localRoot,TreeNode* p, TreeNode* q){
         TreeNode* ptr = localRoot;
        stack<TreeNode*> st;
        bool isFoundP = false;
        bool isFoundQ = false;
        while(ptr!=NULL||!st.empty()){
            while(ptr!=NULL){
                st.push(ptr);
                ptr = ptr->left;
            }
            if(ptr==NULL&&!st.empty()){
                ptr = st.top();
                st.pop();
                if(ptr==p){
                    isFoundP = true;
                }
                else if(ptr==q){
                    isFoundQ = true;
                }
                ptr = ptr->right;
            }
        }
        return isFoundP&&isFoundQ;
    }
    TreeNode* helper(TreeNode *localRoot, TreeNode* p, TreeNode* q){
        if(isPresent(localRoot->left,p,q)){
            return helper(localRoot->left,p,q);
            
        }
        else if(isPresent(localRoot->right,p,q)){
            return helper(localRoot->right,p,q);
            
        }
        return localRoot;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = NULL;
        lca = helper(root,p,q);
        return lca;
    }
};
