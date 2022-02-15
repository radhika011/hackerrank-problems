/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Now how tf did i solve this DP hard problem?


*/





class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int ans = 0;
        for(int i = 0;i<n;i++){
            int curr = 0;
            int time = 1;
            for(int j = i;j<n;j++){
                curr+=time*satisfaction[j];
                time++;
            }
            ans = max(ans,curr);
        }
        return ans;
        
    }
};
