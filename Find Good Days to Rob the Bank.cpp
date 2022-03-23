
/*
You and a gang of thieves are planning on robbing a bank. You are given a 0-indexed integer array security, where security[i] is the number of guards on duty on the ith day. The days are numbered starting from 0. You are also given an integer time.

The ith day is a good day to rob the bank if:

There are at least time days before and after the ith day,
The number of guards at the bank for the time days before i are non-increasing, and
The number of guards at the bank for the time days after i are non-decreasing.
More formally, this means day i is a good day to rob the bank if and only if security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].

Return a list of all days (0-indexed) that are good days to rob the bank. The order that the days are returned in does not matter.

It's okay if we don't think about booleans. Substitute numbers for boolean


*/



class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> memo1(n,0);
        for(int i = 1;i<n;i++){
            if(security[i-1]>=security[i]){
                memo1[i] = 1+memo1[i-1];
            }
            //cout<<memo1[i]<<" ";
        }
        //cout<<endl;
       
        vector<int> memo2(n,0);
        for(int i = n-2;i>=0;i--){
            if(security[i+1]>=security[i]){
                memo2[i] = 1+memo2[i+1];
            }
            //cout<<memo2[i]<<" ";
        }
        //cout<<endl;
        //reverse(memo2.begin(),memo2.end());
       
        vector<int> ans;
        for(int i = time;i<(n-time);i++){
            if(memo1[i]>=time&&memo2[i]>=time){
                ans.push_back(i);
            }
        }
        return ans;
        
        
    }
};
