
/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.





*/













class Solution {
public:
    
    
    int search(TreeNode* root, int start,unordered_map<int,int>& vals){
        if(root==NULL) return INT_MAX;
        if(root->val==start){
            vals[start] = 0;
            int l = search(root->left,start,vals);
            int r = search(root->right,start,vals);
            
            
            return 0;
        }
        int l = search(root->left,start,vals);
        int r = search(root->right,start,vals);
        //cout<<root->val<<" "<<l<<" "<<r<<endl;
        if(l!=INT_MAX){
            vals[root->val] = 1+l;
            
            return l+1;
        }
        else if(r!=INT_MAX){
            
            vals[root->val] = r+1;
            return r+1;
        }
        vals[root->val] = INT_MAX;
        return INT_MAX;
    }
    
    void update(TreeNode* root,int currexp,unordered_map<int,int>& vals,int& ans){
        if(root==NULL) return;
        int curr = vals[root->val];
        currexp = min(currexp+1,curr);
        
        update(root->left,currexp,vals,ans);
        update(root->right,currexp,vals,ans);
        ans = max(ans,currexp);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,int> vals;
        search(root,start,vals);
        int ans = INT_MIN;
        update(root,vals[root->val],vals,ans);
        return ans;
    }
};
