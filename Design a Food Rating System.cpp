/*
Design a food rating system that can do the following:

Modify the rating of a food item listed in the system.
Return the highest-rated food item for a type of cuisine in the system.
Implement the FoodRatings class:

FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.
foods[i] is the name of the ith food,
cuisines[i] is the type of cuisine of the ith food, and
ratings[i] is the initial rating of the ith food.
void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.
Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.



*/




class CustCompare
{
public:
    bool operator()(pair<int,string> p1,pair<int,string> p2) {
         if(p1.first==p2.first) return p1.second>p2.second;
        return p1.first<p2.first;
    }
};
class FoodRatings {
public:
    unordered_map<string,int> updated;
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,CustCompare>> heaper;
    unordered_map<string,string> mapper;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i =0;i<n;i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            updated[food] = rating;
            heaper[cuisine].push({rating,food});
            mapper[food] = cuisine;
        }
    }
    
    void changeRating(string food, int newRating) {
        updated[food] = newRating;
        string cuisine = mapper[food];
        heaper[cuisine].push({newRating,food});
        
    }
    
    string highestRated(string cuisine) {
        while(!heaper[cuisine].empty()){
            int rating = heaper[cuisine].top().first;
            string food = heaper[cuisine].top().second;
            if(updated[food]==rating) return food;
            heaper[cuisine].pop();
        }
        return "";
    }
};
