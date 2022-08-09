/*

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.





*/






typedef long long ll;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_map<int,ll> umap;
        int mod = pow(10,9)+7;
        ll ans = 0;
        for(int i =0;i<n;i++){
            int curr = arr[i];
            umap[arr[i]] = 1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    umap[arr[i]] += (umap[arr[j]]*umap[arr[i]/arr[j]]);
                }
            }
            ans+=umap[arr[i]];
        }
        return ans%mod;
    }
};
