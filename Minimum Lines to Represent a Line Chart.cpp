/*

You are given a 2D integer array stockPrices where stockPrices[i] = [dayi, pricei] indicates the price of the stock on day dayi is pricei. A line chart is created from the array by plotting the points on an XY plane with the X-axis representing the day and the Y-axis representing the price and connecting adjacent points. One such example is shown below:

IS LONG DOUBLE EVEN A THING? LOL



*/






class Solution {
public:
    
    
    static bool sorter(vector<int>& v1,vector<int>& v2){
        return v1[0]<v2[0];
    }
    
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        long double prev_m = INT_MAX;
        sort(stockPrices.begin(),stockPrices.end(),sorter);
        int ans = 0;
        for(int i = 1;i<n;i++){
            long double x1 = stockPrices[i-1][0];
            long double x2 = stockPrices[i][0];
            long double y1 = stockPrices[i-1][1];
            long double y2 = stockPrices[i][1];
            long double m = (y2-y1)/(x2-x1);
            //cout<<x1<<" "<<y1<<endl;
            //cout<<x2<<" "<<y2<<endl;
            //cout<<m<<endl;
            if(m!=prev_m){
                ans+=1;
            }
            prev_m = m;
        }
        return ans;
    }
};
