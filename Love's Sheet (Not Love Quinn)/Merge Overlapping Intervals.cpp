
/*

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover 
all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

*/

class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[0]==v2[0]) return v1[1]<v2[1];
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i =0;i<n;){
            vector<int> part;
            part.push_back(intervals[i][0]);
            int maxEnd = intervals[i][1];
            int j = i;
            while(j<n&&intervals[j][0]<=maxEnd){
                maxEnd = max(maxEnd,intervals[j][1]);
                j++;
                
            }
            part.push_back(maxEnd);
            ans.push_back(part);
            i = j;
        }
        return ans;
    }
    
};
//Follow up - For infinite stream?
//See Interval Tree
