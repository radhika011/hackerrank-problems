/*

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.


*/




class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans = INT_MIN;
        while(i<j){
            int width = j-i;
            int ht = min(height[i],height[j]);
            int area = width*ht;
            ans = max(ans,area);
            if(height[i]<height[j]){
                i++;
                continue;
            }
            j--;
        }
        return ans;
    }
};
