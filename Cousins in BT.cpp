class Solution {
public:
 vector<int> parents;
    vector<int> depths;
    void dfs(TreeNode* node, TreeNode* parent,int depth,int x,int y){
        if(node==NULL) return;
        if(node->val==x||node->val==y){
            if(parent!=NULL) parents.push_back(parent->val);
            depths.push_back(depth);
        }
        dfs(node->left,node,depth+1,x,y);
        dfs(node->right,node,depth+1,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
       dfs(root,NULL,0,x,y);
        if(parents.size()!=2||depths.size()!=2) return false;
        if(depths[0]!=depths[1]) return false;
        if(parents[0]==parents[1]) return false;
        return true;
    }
};
