class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int INF = 100000;
        vector<int> jumps(n,INF);
        jumps[0] = 0;
        for(int i =0;i<n;i++){
            int jumpsUptoNow = jumps[i];
            int max = nums[i];
            int k = i+1;
            for(int j =0;j<max&&k<n;j++){
                jumps[k] = min(jumps[k],1+jumpsUptoNow);
                k++;
            }
        }
        return jumps[n-1];
    }
};
