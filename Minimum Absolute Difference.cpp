
/*

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr


*/




class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
         vector<vector<int>> ans;
        int minDiff = INT_MAX;
        for(int i =1;i<n;i++){
            int currDiff = abs(arr[i]-arr[i-1]);
            if(currDiff<=minDiff){
                if(currDiff<minDiff) ans.clear();
                vector<int> curr;
                curr.push_back(arr[i-1]);
                curr.push_back(arr[i]);
                ans.push_back(curr);
                minDiff = currDiff;
            }
        }
        return ans;
    }
};
