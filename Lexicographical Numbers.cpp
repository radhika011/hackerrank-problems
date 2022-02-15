/*

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

*/




class Solution {
public:
     vector<int> ans;
    int n;
    void helper(int curr){
       if(curr>n) return;
       if(curr!=0){
           ans.push_back(curr);
           helper(curr*10);
       }
        
       for(int i = 1;i<=9;i++){
           if((curr+i)<=n) ans.push_back(curr+i);
           helper((curr+i)*10);
       }
    }
    
    
    
    vector<int> lexicalOrder(int n) {
       this->n = n;
        helper(0);
        return ans;
    }
};
