/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)



*/





class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* ptr = head;
        ListNode* next_ptr = head->next;
        while(next_ptr!=NULL){
            prev->next = next_ptr;
            ptr->next = next_ptr->next;
            next_ptr->next = ptr;
            prev = ptr;
            ptr = ptr->next;
            if(ptr!=NULL) next_ptr = ptr->next;
            else next_ptr = NULL;
        }
        return dummy->next;
        
    }
};
