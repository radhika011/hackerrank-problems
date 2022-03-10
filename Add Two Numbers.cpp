/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.




*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;
        int carry = 0;
        while(ptr1!=NULL||ptr2!=NULL){
            int n1 = 0;
            int n2 = 0;
            if(ptr1!=NULL) n1 = ptr1->val;
            if(ptr2!=NULL) n2 = ptr2->val;
            int ans = carry+n1+n2;
            ListNode* newNode = new ListNode(ans%10);
            ptr->next = newNode;
            ptr = ptr->next;
            if(ans/10!=0) carry = 1;
            else carry = 0;
            if(ptr1!=NULL) ptr1 = ptr1->next;
            if(ptr2!=NULL) ptr2 = ptr2->next;
        }
        if(carry!=0){
             ListNode* newNode = new ListNode(1);
                ptr->next = newNode;
        }
        return head->next;
        
    }
};
