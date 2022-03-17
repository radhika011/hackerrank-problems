/*
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.



*/





class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<string> st;
        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(ch=='('){
                st.push(string(1,ch));
                continue;
            }
            if(st.top()=="("){
                st.pop();
                st.push(to_string(1));
            }
            else{
                int score = 0;
                while(st.top()!="("){
                    score+=stoi(st.top());
                    st.pop();
                }
                st.pop();
                st.push(to_string(2*score));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans+=stoi(st.top());
            st.pop();
        }
        return ans;
    }
};
