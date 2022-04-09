/*

Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.

REALLY COOL HACK FOR ADDING NUMBERS TO A RANGE OF ELEMENTS
CONSIDER THE SLOPE

*/



long arrayManipulation(int n, vector<vector<int>> queries) {
    int m = queries.size();
    vector<long> arr(n,0);
    
    for(int i =0;i<m;i++){
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];
        arr[a-1] += k;
        if((b)!=n) arr[b] -= k;
        }
      
    long ans = 0;
    long past = 0;
    for(int i = 0;i<n;i++){
          
        long curr =  past+arr[i];
        past+=arr[i];
        if(curr>ans){
            ans = curr;
        }
    }
    //cout<<"here"<<endl;
    return ans;
}
