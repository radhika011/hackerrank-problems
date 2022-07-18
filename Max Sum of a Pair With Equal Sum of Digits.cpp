/*


You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.



*/





class Solution {
public:
    
    
    
    int sumOfDigits(int curr){
        int sum = 0;
        string s = to_string(curr);
        for(int i =0;i<s.size();i++){
            sum+=(s[i]-'0');
        }
        return sum;
        
    }
    
    static bool sorter(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
    
    
    
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> repo;
        for(int i =0;i<n;i++){
            int currSum = sumOfDigits(nums[i]);
            repo.push_back({nums[i],currSum});
            
        }
        sort(repo.begin(),repo.end(),sorter);
        //for(int i =0;i<n;i++){
            //cout<<repo[i].first<<" "<<repo[i].second<<endl;
        //}
        int i = 0;
        int j = 1;
        int maxSum = -1;
        while(j<n){
            if(repo[i].second==repo[j].second){
                maxSum = max(maxSum,repo[i].first+repo[j].first);
            }
            i++;
            j++;
        }
        return maxSum;
        
    }
};
