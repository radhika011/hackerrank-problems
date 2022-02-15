
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.



*/






class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(int i = 0;i<tokens.size();i++){
            //cout<<tokens[i]<<endl;
            string curr = tokens[i];
            if(isdigit(curr[0])||(curr.size()>1)){
                
                int digit = stoi(curr);
                st.push(digit);
                continue;
            }
            //cout<<"Size:"<<st.size()<<endl;
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int res = 0;
            if(curr=="+"){
                res = op1+op2;
            }
            else if(curr=="-"){
                res = op1-op2;
            }
            else if(curr=="*"){
                res = op1*op2;
            }
            else{
                res = op1/op2;
            }
            st.push(res);
        }
        
        return st.top();
        
        //cout<<(6/-3)<<endl;
        //return 0;
    }
};
