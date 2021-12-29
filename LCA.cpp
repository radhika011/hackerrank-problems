//WTH IS THIS EVEN
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
//THE ACTUAL ANSWER: POINTER TO POINTER
class Solution {
public:
    
    bool lookFor(TreeNode* root,TreeNode* p, TreeNode* q,TreeNode** ans){
        if(root==NULL) return false;
        if(root==p||root==q){
            bool lookForLeft = lookFor(root->left,p,q,ans);
            bool lookForRight = lookFor(root->right,p,q,ans);
            if(lookForLeft||lookForRight){
                *ans = root;
               
            }
            return true;
            
            
            
        }
        bool lookForLeft = lookFor(root->left,p,q,ans);
        bool lookForRight = lookFor(root->right,p,q,ans);
        
            
            if(lookForLeft&&lookForRight){
                
                *ans = root;
                //cout<<(*ans)->val<<endl;
                return false;
            }
           
         if(lookForLeft||lookForRight) return true;
        return false;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        lookFor(root,p,q,&ans);
        //cout<<(*ans)->val<<endl;
        return ans;
    }
};
