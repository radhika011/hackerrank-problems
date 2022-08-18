/*

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.




*/









class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int n = words.size();
        unordered_set<string> visited;
        int ans = 0;
        
        vector<string> mapping = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i =0;i<n;i++){
            string curr = words[i];
            string currans = "";
            for(int j = 0;j<curr.size();j++){
                
                string part = mapping[(curr[j]-97)];
                currans+=part;
            }
            if(visited.find(currans)==visited.end()){
                ans++;
                visited.insert(currans);
            }
            
            
        }
        return ans;
    }
};
