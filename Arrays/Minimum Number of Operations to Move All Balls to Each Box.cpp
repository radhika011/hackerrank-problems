class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ones;
        vector<int> ans;
        int n = boxes.size();
        for(int i =0;i<n;i++){
            char curr = boxes[i];
            if(curr=='1') ones.push_back(i);
        }
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = 0;j<ones.size();j++){
                sum+=abs(ones[j]-i);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
