/*
A string s can be partitioned into groups of size k using the following procedure:

The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each character can be a part of exactly one group.
For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.




*/
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        for(int i =0;i<=n-k;i+=k){
            string curr = "";
            for(int j = 0;j<k;j++){
                curr+=s[i+j];
            }
            ans.push_back(curr);
            //cout<<curr<<endl;
        }
        int extra = n%k;
       int fillers = k-extra;
        if(extra==0) return ans;
        string curr = s.substr(n-extra,n);
        //cout<<curr<<endl;
        for(int i =0;i<fillers;i++){
            curr+=fill;
        }
        ans.push_back(curr);
        
        return ans;
    }
};
