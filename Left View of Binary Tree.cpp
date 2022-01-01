

/*

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.


*/


vector<int> leftView(Node *root)
{
   // Your code here
   
   queue<Node*> q;
   q.push(root);
   vector<int> ans;
   if(root==NULL) return ans;
   while(!q.empty()){
       queue<Node*> dq;
       ans.push_back(q.front()->data);
       while(!q.empty()){
           Node* curr = q.front();
           q.pop();
           if(curr->left!=NULL) dq.push(curr->left);
           if(curr->right!=NULL) dq.push(curr->right);
       }
       q = dq;
       
       
   }
   return ans;
}
