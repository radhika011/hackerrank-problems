class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode * ptr2 = l2;
        ListNode *head = NULL;
        ListNode *ptr = head;
        while(ptr1!=NULL&&ptr2!=NULL){
            int nextVal = 0;
            bool isPtr1 = false;
            if(ptr1->val<=ptr2->val){
                isPtr1 = true;
                nextVal = ptr1->val;
            }
            else{
                nextVal = ptr2->val;
            }
            ListNode *newNode = new ListNode(nextVal);
            if(head==NULL){
                
                head = newNode;
                ptr = head;
                if(isPtr1) ptr1 = ptr1->next;
                else ptr2 = ptr2->next;
            }
            else{
                ptr->next = newNode;
                ptr = newNode;
                if(isPtr1) ptr1 = ptr1->next;
                else ptr2 = ptr2->next;
                
            }
        }
        while(ptr1!=NULL){
            ListNode *newNode = new ListNode(ptr1->val);
            if(head==NULL){
                head = newNode;
                ptr = head;
            }
            else{
                ptr->next = newNode;
                ptr = newNode;
            }
            ptr1 = ptr1->next;
        }
        while(ptr2!=NULL){
            ListNode *newNode = new ListNode(ptr2->val);
            if(head==NULL){
                head = newNode;
                ptr = head;
            }
            else{
                ptr->next = newNode;
                ptr = newNode;
            }
            ptr2 = ptr2->next;
        }
        return head;
    }
};
