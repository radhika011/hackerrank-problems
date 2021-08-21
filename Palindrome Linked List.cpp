class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> st;
        while(fast!=NULL&&fast->next!=NULL){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL){
            slow = slow->next;
        }
        while(slow!=NULL){
            int curr = st.top();
            st.pop();
            if(curr!=slow->val) return false;
            slow = slow->next;
        }
        return true;
        
    }
};
