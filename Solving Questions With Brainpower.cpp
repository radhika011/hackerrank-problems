/*

You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.



*/
typedef long long ll;
class Solution {
public:
    
    ll maxPts(int curr,int n,vector<vector<int>>& questions){
        if(curr>=n){
            return 0;
        }
        ll option1 = questions[curr][0]+maxPts(curr+questions[curr][1]+1,n,questions);
        ll option2 = maxPts(curr+1,n,questions);
        //cout<<curr<<" "<<option1<<" "<<option2<<endl;
        return max(option1,option2);
    }
    
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> memo(n,0);
        memo[n-1] = questions[n-1][0];
        for(int i = n-2;i>=0;i--){
            ll currBp = questions[i][1];
            ll currScore = questions[i][0];
            if(currBp+i+1>=n){
                memo[i] = max(currScore,memo[i+1]);
            }
            else{
                ll option1 = currScore+memo[i+currBp+1];
                memo[i] = max(option1,memo[i+1]);
            }
            
            
        }
        return memo[0];
    }
};
