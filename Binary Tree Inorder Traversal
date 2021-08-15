class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* ptr = root;
        stack<TreeNode*> st;
        while(ptr!=NULL||!st.empty()){
            while(ptr!=NULL){
                st.push(ptr);
                ptr = ptr->left;
            }
            if(ptr==NULL&&!st.empty()){
                ptr = st.top();
                st.pop();
                ans.push_back(ptr->val);
                ptr = ptr->right;
            }
        }
        return ans;
        
        
    }
};
