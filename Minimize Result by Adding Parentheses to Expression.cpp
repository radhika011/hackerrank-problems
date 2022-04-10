/*
You are given a 0-indexed string expression of the form "<num1>+<num2>" where <num1> and <num2> represent positive integers.

Add a pair of parentheses to expression such that after the addition of parentheses, expression is a valid mathematical expression and evaluates to the smallest possible value. The left parenthesis must be added to the left of '+' and the right parenthesis must be added to the right of '+'.

Return expression after adding a pair of parentheses such that expression evaluates to the smallest possible value. If there are multiple answers that yield the same result, return any of them.

The input has been generated such that the original value of expression, and the value of expression after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.







*/






class Solution {
public:
    string parse_string(int lm,int la,int ra,int rm,bool a,bool b){
        
        string ans = "";
        if(!a)ans+=to_string(lm);
        ans+='(';
        ans+=to_string(la);
        ans+='+';
        ans+=to_string(ra);
        ans+=')';
        if(!b)ans+=to_string(rm);
        return ans;
    }
    string minimizeResult(string expression) {
        string num1 = "";
        string num2 = "";
        bool plus = false;
        for(int i =0;i<expression.size();i++){
            if(expression[i]=='+'){
                plus = true;
                i++;
            }
            if(plus){
                num2+=expression[i];
            }
            else num1 +=expression[i];
        }
        //cout<<num1<<endl;
        //cout<<num2<<endl;
        int minans = INT_MAX;
        string ans = "";
        for(int i =0;i<num1.size();i++){
            int lm = 1;
            bool startA = true;
            if(i!=0){
                lm = stoi(num1.substr(0,i));
                startA = false;
            }
            int la = stoi(num1.substr(i,num1.size()));
            //cout<<"left "<<lm<<" "<<la<<endl;
            for(int j = num2.size();j>0;j--){
                int rm = 1;
                bool startB = true;
                if(j!=num2.size()){
                    rm = stoi(num2.substr(j,num2.size()));
                    startB = false;
                }
                int ra = stoi(num2.substr(0,j));
                int curr = lm*(la+ra)*rm;
                //cout<<"right "<<rm<<" "<<ra<<endl;
                if(curr<minans){
                    ans = parse_string(lm,la,ra,rm,startA,startB);
                    minans = curr;
                }
            }
            
        }
        //cout<<minans<<endl;
        //cout<<"here"<<endl;
        return ans;
    }
};
