/*


Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.






*/








class Solution {
public:
    
    
    TreeNode* rec(ListNode* head,ListNode* tail){
        if(head==NULL||tail==NULL) return NULL;
        if(head==tail){
            return  new TreeNode(head->val);
        }
      
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast!=NULL&&fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //cout<<head->val<<" "<<prev->val<<endl;
        //if(slow->next!=NULL) cout<<slow->next->val<<" "<<tail->val<<endl;
        //cout<<endl;
        TreeNode* newNode = new TreeNode(slow->val);
        newNode->right = rec(slow->next,tail);
        prev->next = NULL;
        newNode->left = rec(head,prev);
        return newNode;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tail = head;
        if(tail==NULL) return NULL;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        return rec(head,tail);
        
        
    }
}; 
