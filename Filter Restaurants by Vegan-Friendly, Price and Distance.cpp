/*
Given the array restaurants where  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]. You have to filter the restaurants using three filters.

The veganFriendly filter will be either true (meaning you should only include restaurants with veganFriendlyi set to true) or false (meaning you can include any restaurant). In addition, you have the filters maxPrice and maxDistance which are the maximum value for price and distance of restaurants you should consider respectively.

Return the array of restaurant IDs after filtering, ordered by rating from highest to lowest. For restaurants with the same rating, order them by id from highest to lowest. For simplicity veganFriendlyi and veganFriendly take value 1 when it is true, and 0 when it is false.


*/




class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = restaurants.size();
        vector<int> ans;
        vector<pair<int,int>> temp;
        for(int i =0;i<n;i++){
            if(restaurants[i][3]<=maxPrice&&restaurants[i][4]<=maxDistance){
                if(veganFriendly==1&&restaurants[i][2]==0) continue;
               
                temp.push_back({restaurants[i][1],restaurants[i][0]});
            }
        }
        sort(temp.begin(),temp.end());
        for(int i =0;i<temp.size();i++){
            ans.push_back(temp[i].second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
