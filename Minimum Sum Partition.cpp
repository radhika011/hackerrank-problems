public:
  vector<int> subsetSum(int arr[],int sum,int n){
      bool dp[n+1][sum+1];
      for(int i =0;i<=n;i++){
          dp[i][0] = true;
      }
      for(int j = 1;j<=sum;j++){
          dp[0][j] = false;
      }
      for(int i =1;i<=n;i++){
          for(int j =  1;j<=sum;j++){
              if(arr[i-1]<=j){
                  dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
              }
              else{
                  dp[i][j] = dp[i-1][j];
              }
          }
      }
      vector<int> vec;
      for(int i =0;i<=sum/2;i++){
          if(dp[n][i]==true) vec.push_back(i);
      }
      
      
      return vec;
      
      
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum =0;
	    for(int i =0;i<n;i++){
	        sum+=arr[i];
	    }
	    vector<int> ans = subsetSum(arr,sum,n);
	    int element = ans[ans.size()-1];
	    int result = sum-(2*element);
	    return result;
	    
	} 
};
