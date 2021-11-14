//Inefficient

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = INT_MIN;
        for(int i =0;i<prices.size();i++){
            for(int j = i;j<prices.size();j++){
                int diff = prices[j]-prices[i];
                if(diff>max) max = diff;
            }
        }
        return max;
    }
};


//For variation - 
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39038/Kadane's-Algorithm-Since-no-one-has-mentioned-about-this-so-far-:)-(In-case-if-interviewer-twists-the-input)
