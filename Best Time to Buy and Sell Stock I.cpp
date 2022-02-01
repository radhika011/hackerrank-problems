//Inefficient - O(n^2)

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

//Efficient - O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxDiff = 0;
        int lower = prices[0];
        for(int i =1;i<n;i++){
           
            int currDiff = prices[i]-lower;
            maxDiff = max(maxDiff,currDiff);
            lower = min(lower,prices[i]);
        }
        return maxDiff;
    }
};
