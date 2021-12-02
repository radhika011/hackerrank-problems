/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.





*/



class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            n++;
            ptr = ptr->next;
        }
        
        
        vector<ListNode*> ans(k,NULL);
        if(n==0) return ans;
        ptr = head;
        int rem = n%k;
        int parts = n/k;
        if(parts==0){

            ListNode* fut = ptr->next;
            int count = 0;
            ListNode* prev = ptr;
            while(ptr!=NULL){
                ListNode* currHead = ptr;
                prev = ptr;
                ptr = ptr->next;
                ans[count++] = currHead;
                prev->next = NULL;
            }
            return ans;
        }
        for(int i = 0;i<k;i++){
            ListNode* currHead = ptr;
            int maximum = rem<=0?parts:1+parts;
            ListNode* prev = currHead;
            for(int j = 0;j<maximum;j++){
                prev = ptr;
                ptr = ptr->next;
            }
            rem--;
            prev->next = NULL;
            ans[i] = currHead;
            
        }
        return ans;
    }
};
