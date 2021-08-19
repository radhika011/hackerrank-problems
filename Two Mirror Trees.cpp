class Solution
{
    public:
    int areMirror(Node* a, Node* b) {
    // Your code here
        if(a==NULL&&b==NULL){
            return 1;
        }
        else if(a==NULL||b==NULL){
            return 0;
        }
        else if(a->data!=b->data){
            return 0;
        }
        return areMirror(a->left,b->right)&&areMirror(a->right,b->left);
    }

};
