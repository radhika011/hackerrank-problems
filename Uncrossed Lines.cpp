
/*
You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.




*/



//Recursive
class Solution {
public:
    unordered_map<int,vector<int>> mapper;
    vector<int> nums1;
    vector<int> nums2;
    int helper(int currInd,int limit){
        if(currInd==nums1.size()){
            return 0;
        }
        if(limit==nums2.size()){
            return 0;
        }
        int curr = nums1[currInd];
        if(mapper.find(curr)==mapper.end()){
            return helper(currInd+1,limit);
        }
        vector<int> allowed = mapper[curr];
        int ans = INT_MIN;
        for(int i =0;i<allowed.size();i++){
            int ind = allowed[i];
            if(ind<limit) continue;
            ans = max(ans,helper(currInd+1,ind+1));
        }
        int option2 = helper(currInd+1,limit);
        return max(1+ans,option2);
        
    }
    
    
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>> mapper;
        for(int i = 0;i<nums2.size();i++){
            mapper[nums2[i]].push_back(i);
        }
        this->mapper = mapper;
        this->nums1 = nums1;
        this->nums2 = nums2;
        return helper(0,0);
        
    }
};
//DP - Longest Common Subsequence exact
vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i = 1;i<=nums1.size();i++){
            //int curr = nums1[i-1];
            for(int j = 1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return dp[nums1.size()][nums2.size()];
