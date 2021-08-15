class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* ptr= node;
        while(ptr->next->next!=NULL){
            ptr->val = ptr->next->val;
            ptr = ptr->next;
        }
        ptr->val = ptr->next->val;
        ptr->next = NULL;
    }
};
