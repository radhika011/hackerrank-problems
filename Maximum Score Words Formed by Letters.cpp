/*
Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

It's low key freaking me out if my solution for a hard is AC on first try


*/



class Solution {
public:
    
    int n;
    vector<string> words;
    
    int helper(unordered_map<char,pair<int,int>> repo,int curr){
        if(curr==n){
            return 0;
        }
        string currWord = words[curr];
        //Option 1: Take the word
        //First check if it can be taken. If yes, explore both options. If not, op2 is the only option
        int op1 = INT_MIN;
        int posScore = 0;
        bool flag = true;
        unordered_map<char,pair<int,int>> temp = repo;
        for(int i = 0;i<currWord.size();i++){
            int currChar = currWord[i];
            int rem = temp[currChar].first;
            if(rem==0){
                flag = false;
                break;
            }
            temp[currChar].first-=1;
            posScore+=temp[currChar].second;
        }
        //cout<<currWord<<" "<<flag<<" "<<posScore<<endl;
        if(flag){
            op1 = posScore+helper(temp,curr+1);
        }
        
        
        //Option 2: Exclude the word
        int op2 = helper(repo,curr+1);
        return max(op1,op2);
        
    }
    
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,pair<int,int>> repo; //freq,score
        for(int i = 0;i<letters.size();i++){
            int curr = letters[i];
            repo[curr].first+=1;
            repo[curr].second = score[(int)curr-97];
        }
        this->n = words.size();
        this->words = words;
        
        return helper(repo,0);
    }
};
