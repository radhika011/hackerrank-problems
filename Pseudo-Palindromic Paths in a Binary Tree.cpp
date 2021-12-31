
/*

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.




*/



class Solution {
public:
    void helper(TreeNode* curr,vector<int> counts,int& num){
        if(curr==NULL){
            return;
        }
        int currVal = curr->val;
        //cout<<currVal<<endl;
        counts[currVal-1]+=1;
        if(curr->left==NULL&&curr->right==NULL){
           bool flag = false;
            for(int i =0;i<9;i++){
               
                if(counts[i]%2!=0&&flag) return;
                if(counts[i]%2!=0&&!flag){
                    flag = true;
                }
               
            }
            num+=1;
        }
        
        helper(curr->left,counts,num);
        helper(curr->right,counts,num);
    }
    
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int num = 0;
       vector<int> counts(9,0);
        helper(root,counts,num);
        return num;
    }
};
