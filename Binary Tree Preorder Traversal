class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* ptr = root;
        stack<TreeNode*> st;
        vector<int> ans;
        while(ptr!=NULL||!st.empty()){
            while(ptr!=NULL){
                ans.push_back(ptr->val);
                st.push(ptr);
                ptr = ptr->left;
            }
            if(ptr==NULL&&!st.empty()){
                ptr = st.top();
                st.pop();
                ptr = ptr->right;
            }
        }
        return ans;
    }
};
