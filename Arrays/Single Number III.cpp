class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> uset;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            int curr = nums[i];
            if(uset.find(curr)!=uset.end()){
                uset.erase(curr);
                continue;
            }
            uset.insert(curr);
        }
        auto it = uset.begin();
        while(it!=uset.end()){
            ans.push_back((*it));
            it++;
        }
        return ans;
    }
};
