/*

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.



*/



class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> ind;
        set<pair<int,int>> done;
        for(int i = 0;i<n;i++){
            ind[nums[i]] = i;
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            int op1 = nums[i]-k;
            int op2 = nums[i]+k;
            auto it1 = ind.find(op1);
            auto it2 = ind.find(op2);
            if(it1!=ind.end()){
                if(it1->second>i){
                    int lower = nums[i]<=it1->first?nums[i]:it1->first;
                    int higher = nums[i]>it1->first?nums[i]:it1->first;
                    done.insert({lower,higher});
                    ans++;
                }
            }
            if(op1!=op2){
             if(it2!=ind.end()){
                if(it2->second>i){
                    int lower = nums[i]<=it2->first?nums[i]:it2->first;
                    int higher = nums[i]>it2->first?nums[i]:it2->first;
                    done.insert({lower,higher});
                    ans++;
                }
            }
            }
            
        }
        return done.size();
    }
};
