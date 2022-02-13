
/*
You are given a 0-indexed array nums consisting of n positive integers.

The array nums is called alternating if:

nums[i - 2] == nums[i], where 2 <= i <= n - 1.
nums[i - 1] != nums[i], where 1 <= i <= n - 1.
In one operation, you can choose an index i and change nums[i] into any positive integer.

Return the minimum number of operations required to make the array alternating.



*/





class Solution {
public:
    
    static bool comp(pair<int,int> p1,pair<int,int> p2 ){
        //if(p1.second==p2.second) return p1.first>p2.first;
        return p1.second>p2.second;
    }
    
    
    int minimumOperations(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;
        if(n==1) return 0;
        int even = 0;
        int odd = 0;
        for(int i = 0;i<n;i++){
            if(i%2==0){
                even++;
                freq1[nums[i]]++;
            }
            else{
                odd++;
                freq2[nums[i]]++;
            }
        }
        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;
        for(auto it = freq1.begin();it!=freq1.end();it++){
            v1.push_back({it->first,it->second});
        }
         for(auto it = freq2.begin();it!=freq2.end();it++){
            v2.push_back({it->first,it->second});
        }
        sort(v1.begin(),v1.end(),comp);
         sort(v2.begin(),v2.end(),comp);
        int ans = 0;
        //cout<<v1[0].second<<" "<<v2[0].second<<endl;
        if(v1[0].first!=v2[0].first){
            ans+=(even-v1[0].second)+(odd-v2[0].second);
            
        }
        else{
            int op1 = 0;
            int op2 = 0;
            op1+=(odd-v2[0].second);
            if(v1.size()>=2){
                op1+=(even-v1[1].second);
            }
            else{
                op1+=even;
            }
            op2+=(even-v1[0].second);
            if(v2.size()>=2){
                op2+=(odd-v2[1].second);
            }
            else{
                op2+=odd;
            }
            ans = min(op1,op2);
        }
        
        return ans;
    }
};
