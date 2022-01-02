/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree


*/



class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
         queue<pair<Node*,int>> q;
        q.push({root,0});
        vector<int> ans;
        map<int,vector<int>> umap;
        while(!q.empty()){
            int n = q.size();
            for(int i =0;i<n;i++){
                pair<Node*,int> currPair = q.front();
                q.pop();
                Node* curr = currPair.first;
                int currLevel = currPair.second;
                umap[currLevel].push_back(curr->data);
                if(curr->left!=NULL){
                    q.push({curr->left,currLevel-1});
                }
               if(curr->right!=NULL){
                   q.push({curr->right,currLevel+1});
               }
            }
       }
        for(auto it = umap.begin();it!=umap.end();it++){
            int currLevel = (*it).first;
            vector<int> level = (*it).second;
            
            ans.push_back(level[0]);
        }
        
        return ans;
    }

};

