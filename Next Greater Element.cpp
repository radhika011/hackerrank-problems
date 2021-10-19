//Brute force - O(N^2)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> ng;
        for(int i =0;i<nums2.size();i++){
            int nextMax = -1;
            for(int j =i+1;j<nums2.size();j++){
                if(nums2[j]>nums2[i]){
                    nextMax = nums2[j];
                    break;
                }
            }
            ng.insert({nums2[i],nextMax});
        }
        vector<int> ans;
        for(int i =0;i<nums1.size();i++){
            if(ng.find(nums1[i])==ng.end()){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(ng.at(nums1[i]));
        }
        return ans;
    }
};
//Monotonic Stack - O(N)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> ng;
        stack<int> st;
        for(int i =nums2.size()-1;i>=0;i--){
            int nextMax = -1;
            while(!st.empty()&&nums2[i]>st.top()){
                st.pop();
            }
            if(!st.empty()){
                nextMax = st.top();
            }
            st.push(nums2[i]);
            ng.insert({nums2[i],nextMax});
        }
        vector<int> ans;
        for(int i =0;i<nums1.size();i++){
            if(ng.find(nums1[i])==ng.end()){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(ng.at(nums1[i]));
        }
        return ans;
    }
};
