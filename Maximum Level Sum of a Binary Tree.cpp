/*


Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.




*/


//Iterative BFS


class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int gsum = INT_MIN;
        int mlevel = 0;
        int clevel = 0;
        while(!q.empty()){
            queue<TreeNode*> dq;
            int sum = 0;
            while(!q.empty()){
                TreeNode* curr = q.front();
                q.pop();
                sum+=curr->val;
                //cout<<curr->val<<" "<<endl;
                if(curr->left!=NULL) dq.push(curr->left);
                if(curr->right!=NULL) dq.push(curr->right);
            }
            clevel++;
            //cout<<endl;
            q = dq;
            if(sum>gsum){
                mlevel = clevel;
                gsum = sum;
            }
            
        }
        return mlevel;
        
    }
};
