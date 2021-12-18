/*
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.




*/




class Solution {
public:
    void dfs(TreeNode *localRoot,int& gmax,set<TreeNode*>& deepestLeaves,int lmax){
        if(localRoot==NULL) return;
        if(localRoot->left!=NULL||localRoot->right!=NULL){
            dfs(localRoot->left,gmax,deepestLeaves,lmax+1);
            dfs(localRoot->right,gmax,deepestLeaves,lmax+1);
        }
        if(lmax>gmax){
            deepestLeaves.clear();
            deepestLeaves.insert(localRoot);
            gmax = lmax;
        }
        else if(lmax==gmax){
              deepestLeaves.insert(localRoot);
        }
    }
    
    TreeNode* lca(set<TreeNode*> leaves,TreeNode* root){
        TreeNode* ptr = root;
        while(ptr!=NULL){
            if(existAll(leaves,ptr->left)){
                ptr = ptr->left;
            }
            else if(existAll(leaves,ptr->right)){
                ptr = ptr->right;
            }
            else{
                return ptr;
            } 
        }
        return ptr;
    }
    bool existAll(set<TreeNode*> leaves,TreeNode* ptr){
        stack<TreeNode*> st;
        while(ptr!=NULL||!st.empty()){
            while(ptr!=NULL){
                st.push(ptr);
                ptr = ptr->left;
            }
            if(ptr==NULL&&!st.empty()){
                ptr = st.top();
                st.pop();
                auto it = leaves.find(ptr);
                if(it!=leaves.end()){
                     leaves.erase(it);
                     //cout<<leaves.size()<<endl;
                }
                ptr = ptr->right;
            }
        }
        
        if(leaves.size()==0) return true;
        
        return false;
       
    }
        
        
        
    
   
    
    
    
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        set<TreeNode*> leaves;
        int gmax = 0;
        int lmax = 0;
        dfs(root,gmax,leaves,lmax);
        TreeNode *ans = lca(leaves,root);
        
        
        
        return ans;
    }
};
