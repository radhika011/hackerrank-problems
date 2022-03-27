/*

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.


*/



class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;
        set<int> visited;
        vector<vector<int>> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i =0;i<n1;i++){
            int curr = nums1[i];
            bool flag = false;
            for(int j =0;j<n2;j++){
                if(curr==nums2[j]){
                    flag = true;
                }
            }
            if(!flag){
                if(visited.find(curr)==visited.end()) ans1.push_back(curr);
                visited.insert(curr);
            } 
        }
        visited.clear();
        
        
        for(int i =0;i<n2;i++){
            int curr = nums2[i];
            bool flag = false;
            for(int j =0;j<n1;j++){
                if(curr==nums1[j]){
                    flag = true;
                }
            }
            if(!flag){
                if(visited.find(curr)==visited.end()) ans2.push_back(curr);
                visited.insert(curr);
            } 
        }
        
        ans.push_back(ans1);
        ans.push_back(ans2);
        
       // ans = {ans1,ans2};
        return ans;
    }
};
