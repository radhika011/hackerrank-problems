/*
Alice and Bob want to water n plants in their garden. The plants are arranged in a row and are labeled from 0 to n - 1 from left to right where the ith plant is located at x = i.

Each plant needs a specific amount of water. Alice and Bob have a watering can each, initially full. They water the plants in the following way:

Alice waters the plants in order from left to right, starting from the 0th plant. Bob waters the plants in order from right to left, starting from the (n - 1)th plant. They begin watering the plants simultaneously.
If one does not have enough water to completely water the current plant, he/she refills the watering can instantaneously.
It takes the same amount of time to water each plant regardless of how much water it needs.
One cannot refill the watering can early.
Each plant can be watered either by Alice or by Bob.
In case both Alice and Bob reach the same plant, the one with more water currently in his/her watering can should water this plant. If they have the same amount of water, then Alice should water this plant.
Given a 0-indexed integer array plants of n integers, where plants[i] is the amount of water the ith plant needs, and two integers capacityA and capacityB representing the capacities of Alice's and Bob's watering cans respectively, return the number of times they have to refill to water all the plants.



*/




class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int a = 0;
        int b = n-1;
        int refillCount = 0;
        int currA = capacityA;
        int currB = capacityB;
        while(a<=b){
            if(a==b){
                int currMax = max(currA,currB);
                if(currMax<plants[a]) refillCount++;
                break;
            }
            if(currA<plants[a]){
                currA = capacityA;
                refillCount++;
                
            }
            currA-=plants[a];
            if(currB<plants[b]){
                currB = capacityB;
                refillCount++;
            }
            currB-=plants[b];
            a++;
            b--;
        }
        return refillCount;
    }
};
