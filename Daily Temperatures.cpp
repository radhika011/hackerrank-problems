
/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Monotonic Stack
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
       
        int n = temperatures.size();
         vector<int> ans(n,0);
        for(int i =0;i<n;i++){
            if(!st.empty()){
                while(!st.empty()&&temperatures[i]>st.top().first){
                    ans[st.top().second] = i- st.top().second;
                    st.pop();
                }
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};
