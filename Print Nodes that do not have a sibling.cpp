void helperFunc(Node *node,vector<int>& ans){
    if(node!=NULL){
        if(node->left==NULL&&node->right!=NULL){
            ans.push_back(node->right->data);
            helperFunc(node->right,ans);
        }
        else if(node->left!=NULL&&node->right==NULL){
            ans.push_back(node->left->data);
            helperFunc(node->left,ans);
        }
        else if(node->left!=NULL&&node->right!=NULL){
             helperFunc(node->left,ans);
             helperFunc(node->right,ans);
             
        }
    }
}
vector<int> noSibling(Node* node)
{
    vector<int> ans;
    helperFunc(node,ans);
    if(ans.empty()){
        ans.push_back(-1);
    }
    sort(ans.begin(), ans.end());
    return ans;
    // code here
}
