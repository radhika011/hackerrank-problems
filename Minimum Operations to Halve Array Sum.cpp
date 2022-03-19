/*

You are given an array nums of positive integers. In one operation, you can choose any number from nums and reduce it to exactly half the number. (Note that you may choose this reduced number in future operations.)

Return the minimum number of operations to reduce the sum of nums by at least half.


*/




typedef long long ll;
class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<double> q;
        double sum = 0;
        for(int i = 0;i<n;i++){
            q.push(nums[i]);
            sum+=nums[i];
        }
        double goal = sum/2;
        double curr = sum;
        int ans = 0;
        while(true){
            ans++;
            double popped = q.top();
            q.pop();
            double pusher = popped/2;
            curr-=pusher;
            q.push(pusher);
            if(curr<=goal) break;
        }
        return ans;
    }
};
