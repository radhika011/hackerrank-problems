
/*
You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



*/





class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<m;i++){
            int curr = queries[i];
            int size = 0;
            int currSum = nums[0];
            int j = 1;
            for(;j<n+1;j++){
              
                if(currSum>curr){
                    //cout<<currSum<<" "<<curr<<endl;
                    break;
                }
                  if(j==n){
                      size++;
                      break;
                  }
                size++;
                currSum+=nums[j];
                //cout<<currSum<<endl;
            }
            
          //cout<<"new"<<size<<" "<<curr<<endl;
            ans.push_back(size);
        }
        return ans;
    }
};
