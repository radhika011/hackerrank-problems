
/*
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.


*/


class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<int> startBits;
        vector<int> endBits;
        int curr = start;
        while(curr>1){
            int rem = curr%2;
            startBits.push_back(rem);
            curr = curr/2;
        }
        if(curr==1) startBits.push_back(curr);
        curr = goal;
        while(curr>1){
            int rem = curr%2;
            endBits.push_back(rem);
            curr = curr/2;
        }
         if(curr==1) endBits.push_back(curr);
    
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i<startBits.size()&&j<endBits.size()){
        if(startBits[i]!=endBits[j]){
            ans++;
        }
        i++;
        j++;
    }
    while(i<startBits.size()){
        if(startBits[i]==1) ans++;
        i++;
    }
    while(j<endBits.size()){
        if(endBits[j]==1) ans++;
        j++;
    }
    return ans;
    }
};
