/*


You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.






*/







class Solution {
public:
    vector<string> words;
    unordered_map<string,int> target;
    string s;
    bool slidingWindow(int curr){
        unordered_map<string,int> counts;
        int wordSize = words[0].size();
        int used = 0;
         int n = words.size();
        int winSize = n*words[0].size();
        
       
       // cout<<curr<<endl;
        
       
        for(int i = curr;i<(curr+winSize)&&i<s.size();i+=wordSize){
            string sub = s.substr(i,wordSize);
            //cout<<sub<<endl;
            if(target.find(sub)==target.end()||target[sub]==counts[sub]){
                return false;
            }
            counts[sub]+=1;
            used++;
            if(used==n) return true;
        }
        return false;
        
        
        
    }
    
    
    
    
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> target;
        for(int i =0;i<words.size();i++){
            target[words[i]] += 1;
        }
        this->words = words;
        this->s = s;
        this->target = target;
        vector<int> ans;
         int winSize = n*words[0].size();
        int maxSize = (s.size()-winSize);
       
        for(int i =0;i<=maxSize;i++){
           
            bool curr = slidingWindow(i);
            if(curr) ans.push_back(i);
        }
        
        
        
        
        
        return ans;
        
    }
};
