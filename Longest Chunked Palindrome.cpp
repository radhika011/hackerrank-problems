/*
You are given a string text. You should split it to k substrings (subtext1, subtext2, ..., subtextk) such that:

subtexti is a non-empty string.
The concatenation of all the substrings is equal to text (i.e., subtext1 + subtext2 + ... + subtextk == text).
subtexti == subtextk - i + 1 for all valid values of i (i.e., 1 <= i <= k).
Return the largest possible value of k.





*/








class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int i = 0;
        int j = n-1;
        int currWidth = 1;
        int ans =0;
        while(i<j){
           
            string left = text.substr(i,currWidth);
            string right = text.substr(j-currWidth+1,currWidth);
            //cout<<left<<" "<<right<<endl;
            
            
            
            if(left==right){
                ans+=2;
                i = i+currWidth;
                j = j-currWidth;
                currWidth = 1;
            }
            else{
                if((i+currWidth)>(j-currWidth)){
                ans++;
                break;
            }
                currWidth++;
            }
             //cout<<i<<" "<<j<<" "<<currWidth<<endl;
            
        }
        if(i==j) ans++;
        
        return ans;
    }
};
