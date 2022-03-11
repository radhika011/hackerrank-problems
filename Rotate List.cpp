/*
Given the head of a linked list, rotate the list to the right by k places.






*/



class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
           n++;
            ptr = ptr->next;
        }
        if(n==0) return head;
        int rem = k%n;
        rem = n-rem;
        ptr = head;
        for(int i =0;i<rem-1;i++){
            ptr = ptr->next;
        }
        ListNode* newHead = ptr->next;
        if(newHead==NULL) return head;
        ptr->next = NULL;
        ptr = newHead;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = head;
        return newHead;
    }
};
