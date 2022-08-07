




/*



Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


*/

class Solution {
public:
    
    
    vector<long> record(TreeNode* localRoot,bool& ans){
        if(localRoot==NULL) return {LONG_MAX,LONG_MIN};
        long curr = localRoot->val;
        vector<long> l = record(localRoot->left,ans);
        vector<long> r = record(localRoot->right,ans);
        if(l[1]>=curr) ans = false;
        if(r[0]<=curr) ans = false;
        
        long newMin = min(l[0],min(r[0],curr));
        long newMax = max(l[1],max(r[1],curr));
        return {newMin,newMax};
        
    }
    
    
    
    bool isValidBST(TreeNode* root) {
        
        bool ans = true;
        record(root,ans);
        return ans;
        
    }
};
