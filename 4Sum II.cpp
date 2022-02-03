/*

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0



*/



class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> part1;
        unordered_map<int,int> part2;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                int currSum = nums1[i]+nums2[j];
                if(part1.find(currSum)==part1.end()){
                    part1[currSum] = 1;
                    continue;
                }
                part1[currSum]+=1;
            }
        }
        
         for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                int currSum = nums3[i]+nums4[j];
                if(part2.find(currSum)==part2.end()){
                    part2[currSum] = 1;
                    continue;
                }
                part2[currSum]+=1;
            }
        }
        int ans = 0;
        for(auto it = part1.begin();it!=part1.end();it++){
            int curr = (*it).first;
            int freq = (*it).second;
            int comp = -1*curr;
            auto finder = part2.find(comp);
            if(finder==part2.end()) continue;
            ans+=((*finder).second)*freq;
        }
        return ans;
        
    }
};
