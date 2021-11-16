/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]







*/

class Solution {
public:
   
    
    void rec(vector<string> &ans,string curr,int rem,int opening,int closing){
        if(rem==0){
            ans.push_back(curr);
            return;
        }
        if(opening==closing){
            
            
            rec(ans,curr+"(",rem-1,opening+1,closing);
        }
        else if((opening-closing)==rem){
           
            rec(ans,curr+")",rem-1,opening,closing+1);
        }
        else{
            
            
            rec(ans,curr+"(",rem-1,opening+1,closing);
            rec(ans,curr+")",rem-1,opening,closing+1);
            
            
        }
        
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec(ans,"",2*n,0,0);
        //cout<<ans1<<endl;
        return ans;
    }
};
