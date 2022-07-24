/*
You are given an integer array ranks and a character array suits. You have 5 cards where the ith card has a rank of ranks[i] and a suit of suits[i].

The following are the types of poker hands you can make from best to worst:

"Flush": Five cards of the same suit.
"Three of a Kind": Three cards of the same rank.
"Pair": Two cards of the same rank.
"High Card": Any single card.
Return a string representing the best type of poker hand you can make with the given cards.

Note that the return values are case-sensitive.





*/






class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char,int> suiter;
        for(int i =0;i<5;i++){
            suiter[suits[i]]+=1;
        }
        if(suiter.size()==1) return "Flush";
        vector<int> ranker(14,0);
        for(int i =0;i<5;i++){
            ranker[ranks[i]]+=1;
        }
        int maxi = INT_MIN;
        for(int i =0;i<14;i++)
        {
            maxi = max(maxi,ranker[i]);
        }
        if(maxi>=3) return "Three of a Kind";
        if(maxi==2) return "Pair";
        return "High Card";
    }
};
