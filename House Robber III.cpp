/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

*/



//Recursive Naive - TLE
class Solution {
public:
    int rec(TreeNode* localRoot,bool flag){
        if(localRoot==NULL) return 0;
        if(flag){
            return max(localRoot->val+rec(localRoot->left,false)+rec(localRoot->right,false),rec(localRoot->left,true)+rec(localRoot->right,true));
        }
        return rec(localRoot->left,true)+rec(localRoot->right,true);                        
    }
    
    
    
    int rob(TreeNode* root) {
        return rec(root,true);
    }
};
//Memoized 
//Cannot use unordered_map as cache because we must provide the hash func ourselves if we do
class Solution {
public:
    
    int rec(TreeNode* localRoot,bool flag,map<pair<TreeNode*,bool>,int>& cache){
        if(localRoot==NULL){
            return 0;
        }
        pair<TreeNode*,bool> currPair = make_pair(localRoot,flag);
        if(cache.find(currPair)!=cache.end()) return cache[currPair];
        if(flag){
            int option1 = max(localRoot->val+rec(localRoot->left,false,cache)+rec(localRoot->right,false,cache),rec(localRoot->left,true,cache)+rec(localRoot->right,true,cache));
            cache[currPair] = option1;
            return option1;
        }
        int option2 = rec(localRoot->left,true,cache)+rec(localRoot->right,true,cache); 
        cache[currPair] = option2;
        return option2;
    }
  
    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>,int> cache1;
        return rec(root,true,cache1);
    }
};
