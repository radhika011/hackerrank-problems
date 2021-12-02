
/*
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.


*/




class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> st;
        vector<int> ans;
        ListNode* ptr = head;
        int curr = 0;
        while(ptr!=NULL){
            ans.push_back(0);
            if(!st.empty()){
                while(!st.empty()&&ptr->val>st.top().first){
                    ans[st.top().second] = ptr->val;
                    st.pop();
                }
            }
            st.push({ptr->val,curr});
            curr++;
            ptr = ptr->next;
        }
        return ans;
    }
};
