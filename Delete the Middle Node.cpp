/*
Please don't do this dumbassery ever again :)
Tortoise and Hare works without knowing the number of nodes in the LL, that's the whole point ffs
*/
   
   
   
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            n++;
            ptr = ptr->next;
        }
        int offset = 0;
        if(n%2==0) offset++;
        ptr = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        if(fast==NULL) return NULL;
        while(fast!=NULL&&fast->next!=NULL){
            
            ptr = slow;
            slow =slow->next;
            fast = fast->next->next;
        }
        if(offset) {
            ptr= slow;
            slow = slow->next;
        }
        ptr->next = slow->next;
        return head;
    }
};
