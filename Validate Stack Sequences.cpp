/*
Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

 




*/





class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        bool ans = true;
        stack<int> st;
        st.push(pushed[0]);
        int currPop = 0;
        int currPush = 1;
        while(currPop<n){
        if(st.size()==0){
            if(currPush==n) return false;
            st.push(pushed[currPush]);
        }
        while(st.top()!=popped[currPop]){
            if(currPush==n) return false;
            st.push(pushed[currPush]);
            currPush++;
        }
        st.pop();
        currPop++;
        }
        return true;
        
        
        
    }
};
