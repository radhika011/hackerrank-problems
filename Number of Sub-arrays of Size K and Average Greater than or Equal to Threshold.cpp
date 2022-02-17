/*


Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.





*/





class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i<k-1;i++){
            sum+=arr[i];
        }
        int start = 0;
        int end = k-1;
        int ans = 0;
        while(end<n){
            sum+=arr[end];
            int avg = sum/k;
            if(avg>=threshold){
                ans+=1;
            }
            sum-=arr[start];
            start++;
            end++;
        }
        return ans;
    }
};
