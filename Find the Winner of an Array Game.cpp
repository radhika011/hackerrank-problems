/*
Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0, and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.

Return the integer which will win the game.

It is guaranteed that there will be a winner of the game.



*/


class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        
        queue<int> q;
        
        int firstWinner = arr[0]>arr[1]?0:1;
        int temp = k;
        int count = 1;
        int prev = arr[firstWinner];
        for(int i =2;i<n;i++){
            q.push(arr[i]);
        }
        if(firstWinner==0) q.push(arr[1]);
        else q.push(arr[0]);
        k = min(temp,n);
        while(count!=k){
            int currOpponent = q.front();
            q.pop();
            bool flag = true;
            if(currOpponent>prev) flag = false;
            if(!flag){
                count = 1;
                q.push(prev);
                prev = currOpponent;
            }
            else{
                count++;
                q.push(currOpponent);
            }
            
            
            
        }
        return prev;
    }
};
