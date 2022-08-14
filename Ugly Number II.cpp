/*

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.



*/









typedef long long ll;
class Solution {
public:
    
     
    int nthUglyNumber(int n) {
       priority_queue<ll,vector<ll>,greater<ll>> q1;
        int ans = 1;
        q1.push(1);
        unordered_set<long long> visited;
        int k = n;
        while(k!=0){
            long long curr = q1.top();
            
            
                ans = curr;
               
                k--;
            
            q1.pop();
            if(visited.find(2*curr)==visited.end()){
                 visited.insert(2*curr);
                q1.push((2*curr));
            }
            if(visited.find(3*curr)==visited.end()){
                 visited.insert(3*curr);
                q1.push((3*curr));
            }
            if(visited.find(5*curr)==visited.end()){
                 visited.insert(5*curr);
                q1.push((5*curr));
            }
        }
        
        return ans;
    }
};
