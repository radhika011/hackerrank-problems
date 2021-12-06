
/*
Optimize to O(1) space. rn it's only in-place but w/o that.
Still Accepted
*/


class Solution {
public:
    void flatten(TreeNode* root) {
       TreeNode* prev = new TreeNode(1);
        stack<TreeNode*> st;
       map<TreeNode*, TreeNode*> cache;
        TreeNode* ptr = root;
        while(ptr!=NULL||!st.empty()){
            while(ptr!=NULL){
                st.push(ptr);
                cache[ptr] = ptr->right;
                if(ptr!=NULL){
               prev->right = ptr; 
                prev = prev->right;
               // cout<<prev->val<<endl;
                }
                //cout<<ptr->val<<endl;
                ptr = ptr->left;
                
            }
            if(ptr==NULL&&!st.empty()){
                
                ptr = st.top();
              
                st.pop();
               
                
               
                  ptr = cache[ptr];
            }
            
        }
       ptr = root;
        while(ptr!=NULL){
            ptr->left = NULL;
            ptr = ptr->right;
        }
       // return head;
    }
};
