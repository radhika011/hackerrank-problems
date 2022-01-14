/*

In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.


*/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> st;
        while(fast!=NULL&&fast->next!=NULL){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        int maxSum = INT_MIN;
        
        while(slow!=NULL){
            int curr = slow->val;
            int currSum = st.top()+curr;
            st.pop();
            maxSum = max(maxSum,currSum);
            slow = slow->next;
        }
        
        return maxSum;
    }
};
