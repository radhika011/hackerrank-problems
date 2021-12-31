/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.


*/


//Brute Force: O(n^2) 

class Solution {
public:
    void helper(vector<TreeNode*> ancestors,TreeNode* curr,int& gmax){
        if(curr==NULL) return;
        int currVal = curr->val;
        for(int i = 0;i<ancestors.size();i++){
            int anVal = ancestors[i]->val;
            int currDiff = abs(anVal-currVal);
            if(currDiff>gmax) gmax = currDiff;
        }
        ancestors.push_back(curr);
        helper(ancestors,curr->left,gmax);
        helper(ancestors,curr->right,gmax);
    }
    
    
    
    int maxAncestorDiff(TreeNode* root) {
        int gmax = INT_MIN;
        vector<TreeNode*> ancestors;
        helper(ancestors,root,gmax);
        return gmax;
    }
};

//Efficient approach O(n) : Only keep track of max and min values for each branch
class Solution {
public:
    
    void helper(int maxVal,int minVal,TreeNode* curr,int& gmax){
        if(curr==NULL){
            int currDiff = abs(maxVal-minVal);
            if(currDiff>gmax) gmax = currDiff;
            return;
        }
        maxVal = max(maxVal,curr->val);
        minVal = min(minVal,curr->val);
        helper(maxVal,minVal,curr->left,gmax);
        helper(maxVal,minVal,curr->right,gmax);
        
        
    }
    
    
    
    int maxAncestorDiff(TreeNode* root) {
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        int gmax = INT_MIN;
        helper(maxVal,minVal,root,gmax);
        return gmax;
        
    }
};


