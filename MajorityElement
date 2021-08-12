//HashMap Approach
#include<unordered_map>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++){
            int element = nums[i];
            if(umap.find(element)==umap.end()){
                umap[element] =1;
            }
            else{
                int freq = umap[element];
                freq++;
                umap[element] = freq;
                if(freq>nums.size()/2){
                    return element;
                }
            }
        }
        return -1;
    }
};
