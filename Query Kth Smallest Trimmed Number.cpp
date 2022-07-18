/*
You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

Trim each number in nums to its rightmost trimi digits.
Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
Reset each number in nums to its original length.
Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

Note:

To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
Strings in nums may contain leading zeros.

NOT USING A TEMP VARIABLE CONVERTED TLE TO AC :) GTFO




*/





typedef long long ll;
class Solution {
public:
    
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int numQueries = queries.size();
        vector<int> ans;
        
       
        for(int i =0;i<numQueries;i++){
           // cout<<"hello"<<endl;
            int k = queries[i][0];
            int trim = queries[i][1];
            vector<pair<string,int>> converted;
            
            for(int j = 0;j<n;j++){
                
                
                
                
                converted.push_back({nums[j].substr(nums[j].size()-trim,nums[j].size()),j});
        
                
        
                
            }
            sort(converted.begin(),converted.end());
            
            ans.push_back(converted[k-1].second);
        }
        return ans;
    }
};
