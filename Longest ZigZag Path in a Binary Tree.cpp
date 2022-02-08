/*

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.




*/



class Solution {
public:
    int longestZigZag(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        int ans = INT_MIN;
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> curr = q.front();
            q.pop();
            int op1 = (curr.second).first;
            int op2 = (curr.second).second;
            ans = max(ans,max(op1,op2));
            TreeNode* currNode = curr.first;
            if(currNode->left!=NULL) q.push({currNode->left,{op2+1,0}});
            if(currNode->right!=NULL) q.push({currNode->right,{0,op1+1}});
            
            
            
            
        }
        return ans;
    }
};
