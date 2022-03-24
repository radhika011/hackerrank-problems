/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 


*/







class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end(),greater<int>());
        int p1 = 0;
        int p2 = n-1;
        int ans = 0;
        while(p1<=p2){
            int wt = people[p1]+people[p2];
            if(p1==p2){
                wt /= 2;
            }
            if(wt<=limit){
                ans+=1;
                p1++;
                p2--;
                continue;
            }
            ans+=1;
            p1+=1;
        }
        return ans;
    }
};
