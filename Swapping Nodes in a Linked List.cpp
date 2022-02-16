
/*

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

*/

//Also see the fast and slow ptr approach




class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            n++;
            ptr = ptr->next;
        }
        ListNode* ptr1 = head;
        for(int i = 0;i<k-1;i++){
            ptr1 = ptr1->next;
        }
        int rem = n-k+1;
        ListNode* ptr2 = head;
        for(int i =0;i<rem-1;i++){
            ptr2 = ptr2->next;
        }
        int temp = ptr1->val;
        ptr1->val = ptr2->val;
        ptr2->val = temp;
        return head;
    }
};
