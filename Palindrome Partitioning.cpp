/*


Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.



*/





class Solution {
public:
    vector<vector<string>> ans;
    int n;
    string s;
    
    
    
    bool isPalindrome(string s){
        string temp = s;
        reverse(s.begin(),s.end());
        //cout<<s<<" "<<temp<<endl;
        if(s==temp) return true;
        return false;
    }
    
    
    
    void rec(string curr,int ind,vector<string> currAns){
        if(ind==n){
            if(currAns.size()!=0&&curr=="") ans.push_back(currAns);
            return;
        }
        
        vector<string> temp1 = currAns;
        vector<string> temp2 = currAns;
      
        //partition not after ind
        string str = curr+(s[ind]);
        rec(str,ind+1,temp1);
        
         //partition after ind
        str = curr+(s[ind]);
        //cout<<str<<endl;
        if(isPalindrome(str)){
            temp2.push_back(str);
            rec("",ind+1,temp2);
        }
        
        
    }
    
    
    vector<vector<string>> partition(string s) {
        this->n = s.size();
        this->s = s;
        //vector<vector<string>> ans;
        rec("",0,{});
        
        return this->ans;
    }
};
