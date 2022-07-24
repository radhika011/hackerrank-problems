/*
You are given a 0-indexed positive integer array nums and a positive integer k.

A pair of numbers (num1, num2) is called excellent if the following conditions are satisfied:

Both the numbers num1 and num2 exist in the array nums.
The sum of the number of set bits in num1 OR num2 and num1 AND num2 is greater than or equal to k, where OR is the bitwise OR operation and AND is the bitwise AND operation.
Return the number of distinct excellent pairs.

Two pairs (a, b) and (c, d) are considered distinct if either a != c or b != d. For example, (1, 2) and (2, 1) are distinct.

Note that a pair (num1, num2) such that num1 == num2 can also be excellent if you have at least one occurrence of num1 in the array.




*/






typedef long long ll;
//NUMBER OF SET BITS
int getSet(int n){
    int count = 0;
    while(n){
        count += (n&1);
        n>>=1;
    }
    return count;
}
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> visited;
        vector<int> simpler;
        for(int i =0;i<nums.size();i++){
            int setbits = getSet(nums[i]);
            if(visited.find(nums[i])!=visited.end()) continue;
            simpler.push_back(setbits);
            visited.insert(nums[i]);
            //cout<<nums[i]<<" "<<setbits<<endl;
        }
        ll ans = 0;
        
        //cout<<ans<<endl;
        sort(simpler.begin(),simpler.end());
        
        int i = 0;
        int j = simpler.size()-1;
        while(i<j){
            int sum = simpler[i]+simpler[j];
            
            if(sum>=k)
            {
                ans+=(j-i);
                j--;
            }
            else{
                i++;
            }
        }
        ans*=2;
        
        
        for(int i =0;i<simpler.size();i++){
            if((simpler[i]*2)>=k) ans++;
        }
        return ans;
    }
};
