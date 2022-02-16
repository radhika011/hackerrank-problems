
/*

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.



*/




class Solution {
public:
    vector<int> inorder;
    int k;
    void getInorder(TreeNode* localRoot){
        if(localRoot==NULL) return;
        if(inorder.size()>=k) return;
        getInorder(localRoot->left);
        inorder.push_back(localRoot->val);
        getInorder(localRoot->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        getInorder(root);
        return inorder[k-1];
        
    }
};
