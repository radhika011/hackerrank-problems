//TC = O(n), SC = O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* odd = new ListNode(-1);
        ListNode* oddPtr = odd;
        ListNode* even = new ListNode(-1);
        ListNode* evenPtr = even;
        ListNode* ptr = head;
        int k = 1;
        while(ptr!=NULL){
            if(k%2!=0){
                oddPtr->next = new ListNode(ptr->val);
                oddPtr = oddPtr->next;
            }
            else{
                 evenPtr ->next = new ListNode(ptr->val);
                evenPtr = evenPtr ->next;
            }
            ptr = ptr->next;
            k++;
        }
        odd = odd->next;
        even = even->next;
        oddPtr->next = even;
        return odd;
    }
}; 
//TC = O(n), SC = O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;
        while(even!=NULL&&even->next!=NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = temp;
        return head;
    }
}; 
