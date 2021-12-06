/*
We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.

Gets pretty intuitive if worked through







*/


class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0;
        int odd =0;
        for(int i =0;i<position.size();i++){
            if(position[i]%2==0) even++;
            else odd++;
        }
        return min(odd,even);
    }
}; 
