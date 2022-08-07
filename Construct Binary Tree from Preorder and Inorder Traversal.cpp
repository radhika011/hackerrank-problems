/*

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.




*/






class Solution {
public:
    vector<int> preorder;
    vector<int> inorder;
     unordered_map<int,int> indices;
    int n;
    TreeNode* rec(int i,int left,int right){
        if(i>=n) return NULL;
        int curr = preorder[i];
        if(right<left) return NULL;
        if(left==right){
            TreeNode* newRoot = new TreeNode(curr);
            
            return newRoot;
        }
        
        int ind = indices[curr];
        TreeNode* newRoot = new TreeNode(curr);
        newRoot->left = rec(i+1,left,ind-1); 
        newRoot->right = rec(i+(ind-left)+1,ind+1,right);
        return newRoot;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            this->preorder = preorder;
        this->inorder = inorder;
        unordered_map<int,int> indices;
        for(int i =0;i<inorder.size();i++){
            indices[inorder[i]] = i;
        }
        this->n = inorder.size();
        this->indices = indices;
        return rec(0,0,inorder.size()-1);
        
    }
};
