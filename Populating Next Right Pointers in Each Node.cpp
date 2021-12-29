
/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



*/


//Extra Space Approach
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            queue<Node*> dq;
            Node* prev = NULL;
            while(!q.empty()){
                Node* curr = q.front();
                q.pop();
                if(curr!=NULL){
                dq.push(curr->left);
                dq.push(curr->right);
                }
                if(prev!=NULL){
                    prev->next = curr;
                }
                prev = curr;
            }
            q = dq;
        }
        return root;
    }
};
