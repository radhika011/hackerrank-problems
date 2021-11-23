class Solution {
public:
    int rec(TreeNode* localRoot,unordered_map<int,int>& umap){
        if(localRoot==NULL){
            return 0;
        }
        int lsum = rec(localRoot->left,umap);
        int rsum = rec(localRoot->right,umap);
        int total = lsum+rsum+localRoot->val;
        umap[total]+=1;
        return total;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int> umap;
        int total = rec(root,umap);
        int currMax = INT_MIN;
        for(auto it = umap.begin();it!=umap.end();it++){
           // cout<<it->first<<" "<<it->second<<endl;
            if(it->second>currMax){
                ans.clear();
                ans.push_back(it->first);
                currMax = it->second;
                continue;
            }
            if(it->second==currMax){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
