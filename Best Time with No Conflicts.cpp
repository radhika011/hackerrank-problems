/*


You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.




*/





class Solution {
public:
    int n;
     vector<pair<int,int>> sorted;
     vector<vector<int>> memo;
    Solution(){
        vector<vector<int>> memo(1001,vector<int>(1001,-1));
        this->memo = memo;
    }
   int rec(int curr,int maxAge){
       
       if(curr==n){
           return 0;
       }
      //cout<<"here"<<curr<<" "<<maxAge<<endl;
       if(memo[curr][maxAge]!=-1) return memo[curr][maxAge];
       
        
       if(sorted[curr].second<maxAge){
           return memo[curr][maxAge]=rec(curr+1,maxAge);
       }
       return memo[curr][maxAge] = max(rec(curr+1,maxAge),sorted[curr].first+rec(curr+1,sorted[curr].second));
   }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        this->n = scores.size();
      
        for(int i = 0;i<n;i++){
            sorted.push_back({scores[i],ages[i]});
        }
        sort(sorted.begin(),sorted.end());
        
        //this->memo = memo;
        int ans = rec(0,0);
        return ans;
        
    }
};
