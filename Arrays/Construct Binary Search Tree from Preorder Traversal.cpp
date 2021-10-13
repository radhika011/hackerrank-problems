//Monotonic Stack approach
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root = nullptr;
        
        TreeNode* parent = nullptr;
        for(int i =0;i<preorder.size();i++){
            
            TreeNode* node = new TreeNode(preorder[i]);
            if(i==0) root = node;
            parent = nullptr;
            
            while(!st.empty()&&preorder[i]>st.top()->val){
                
                parent = st.top();
                st.pop();
            }
            
            if(parent!=nullptr){
                parent->right = node;
            }
            else if(!st.empty()){
                st.top()->left = node;
            }
            st.push(node);
        }
        return root;
    }
};
