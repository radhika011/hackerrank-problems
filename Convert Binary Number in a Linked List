class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n[30];
        int len= 0;
        int decimal = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            n[len++] = ptr->val; 
            ptr = ptr->next;
        }
        int ind =0;
        for(int i=len-1;i>=0;i--){
            decimal+=(n[ind++]*pow(2,i));
        }
        return decimal;
    }
};
//Correct Approach
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            decimal = decimal*2+ptr->val;
            ptr = ptr->next;
        }
        return decimal;
    }
};
