/*


Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

TC: O(n)


*/

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> sums(n,0);
	    sums[0] = arr[0];
	     int ans = sums[0];
	    
	    for(int i= 1;i<n;i++){
	        int curr = arr[i];
	        int maxPossible = INT_MIN;
	       
	        for(int j = i-1;j>=0;j--){
	            if(curr>arr[j]){
	                maxPossible = max(maxPossible,sums[j]);
	                
	            }
	        }
	        //cout<<arr[i]<<" "<<maxPossible<<endl;
	        if(maxPossible==INT_MIN){
	            sums[i] = arr[i];
	        }
	        else{
	            sums[i] = arr[i]+maxPossible;
	        }
	        ans = max(ans,sums[i]);
	    }
	    return ans;
	    
	    
	}  
};





