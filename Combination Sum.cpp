/*

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



*/




//Backtracking approach



class Solution {
public:
    vector<vector<int>> ans;
    int n;
    vector<int> candidates;
    void helper(int curr,vector<int> path,int rem){
        if(rem<0) return;
        if(rem==0){
            ans.push_back(path);
            return;
        }
        if(curr==n) return;
        int temp = rem;
        int num = candidates[curr];
        vector<int> tempPath = path;
        while(temp>=0){
            helper(curr+1,tempPath,temp);
            tempPath.push_back(num);
            temp-=num;
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        this->n = n;
        this->candidates = candidates;
        vector<int> path;
        helper(0,path,target);
        return ans;
    }
};

//Unbounded Knapsack approach


