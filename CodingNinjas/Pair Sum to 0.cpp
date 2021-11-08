#include<vector>
#include<algorithm>
#include<unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int,int> umap;
    int count = 0;
    for(int i =0;i<n;i++){
        if(arr[i]==0){
            umap[0]++;
            continue;
        }
        int curr = arr[i];
       	int anti = -1*arr[i];
        if(umap.find(anti)!=umap.end()){
            count+=umap[anti];
        }
        umap[arr[i]]++;
    }
  
    if(umap.find(0)!=umap.end()){
    	int zero_count = umap[0];
        count+=(zero_count*(zero_count-1))/2;
    }
    return count;
}
