/*
You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.

You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

Return true if all asteroids can be destroyed. Otherwise, return false.



*/
typedef long long ll;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        ll lessThanSum = 0;
        vector<int> moreThans;
        for(int i =0;i<n;i++){
            if(asteroids[i]<=mass){
                lessThanSum+=asteroids[i];
            }
            else moreThans.push_back(asteroids[i]);
        }
        ll laterMass = mass+lessThanSum;
        sort(moreThans.begin(),moreThans.end());
        for(int i = 0;i<moreThans.size();i++){
            if(moreThans[i]>laterMass) return false;
            laterMass+=moreThans[i];
        }
        return true;
        
        
        
    }
};
