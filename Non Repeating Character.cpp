#include <unordered_map>
class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       unordered_map<char,int> umap;
       char first = '$';
       for(int i =0;i<S.size();i++){
           if(umap.find(S[i])==umap.end()){
               umap.insert({S[i],0});
               continue;
           }
           umap.at(S[i])= INT_MIN;
       }
       for(int i =0;i<S.size();i++){
           if(umap.at(S[i])!=INT_MIN){
               return S[i];
           }
       }
       return '$';
    }

};
