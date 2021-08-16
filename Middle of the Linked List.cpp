//My Approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        int len =0;
        while(ptr!=NULL){
            len++;
            ptr = ptr->next;
        }
        int mid = len/2;
        
        ptr = head;
        for(int i=0;i<mid;i++){
            ptr = ptr->next;
        }
        return ptr;
    }
};
//Fast and Slow ptr approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
         ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
