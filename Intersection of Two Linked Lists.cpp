class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        int count1 = 0;
        int count2 = 0;
        bool isPtr1 = false;
        while(ptr1!=NULL){
            count1++;
            ptr1 = ptr1->next;
        }
        while(ptr2!=NULL){
            count2++;
            ptr2 = ptr2->next;
        }
        ptr1  = headA;
        ptr2 = headB;
        int diff = 0;
        if(count1>count2){
            isPtr1 = true;
            diff = count1-count2;
        }
        else{
            diff = count2 -count1;
        }
        if(isPtr1){
            for(int i =0;i<diff;i++){
                ptr1  = ptr1->next;
            }
        }
        else{
            for(int i =0;i<diff;i++){
                ptr2  = ptr2->next;
            }
        }
        while(ptr1!=NULL){
            if(ptr1==ptr2){
                return ptr1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};
