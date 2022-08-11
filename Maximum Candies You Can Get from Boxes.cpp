/*
You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:

status[i] is 1 if the ith box is open and 0 if the ith box is closed,
candies[i] is the number of candies in the ith box,
keys[i] is a list of the labels of the boxes you can open after opening the ith box.
containedBoxes[i] is a list of the boxes you found inside the ith box.
You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

Return the maximum number of candies you can get following the rules above.





*/






typedef long long ll;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        unordered_set<int> waiting;
        unordered_set<int> allKeys;
        queue<int> q;
        for(int i =0;i<initialBoxes.size();i++){
            if(status[initialBoxes[i]]==0){
                waiting.insert(initialBoxes[i]);
                continue;
            }
           // cout<<initialBoxes[i]<<endl;
            q.push(initialBoxes[i]);
        }
        ll ans = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans+=candies[curr];
           
            for(int i =0;i<keys[curr].size();i++){
                int key = keys[curr][i];
                allKeys.insert(key);
                if(waiting.find(key)!=waiting.end()){
                    q.push(key);
                    waiting.erase(key);  //TC?
                }
            }
            for(int i =0;i<containedBoxes[curr].size();i++){
                int newBox = containedBoxes[curr][i];
                if(status[newBox]==0&&allKeys.find(newBox)==allKeys.end()){
                    waiting.insert(newBox);
                    continue;
                }
                if(status[newBox]==1||allKeys.find(newBox)!=allKeys.end()){
                    q.push(newBox);
                    continue;
                }
            }
        }
        return ans;
    }
};
