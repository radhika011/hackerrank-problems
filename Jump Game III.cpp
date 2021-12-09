/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.




*/



//DFS
class Solution {
public:
    
    bool rec(vector<int>& arr,int n,set<int>& visited){
        if(n<0||n>=arr.size()||visited.find(n)!=visited.end()){
            return false;
        }
        
        if(arr[n]==0) return true;
        visited.insert(n);
        int option1 = rec(arr,n+arr[n],visited);
        int option2 = rec(arr,n-arr[n],visited);
        return option1||option2;
    }
    
    
    
    bool canReach(vector<int>& arr, int start) {
      
       set<int> visited;
        if(arr[start]==0) return true;
        visited.insert(start);
       return rec(arr,start+arr[start],visited)||rec(arr,start-arr[start],visited);
    }
};






// BFS
class Solution {
public:
    
    
    
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
      vector<bool> cache(n,false);
        queue<int> visited;
       
        visited.push(start);
        
        while(!visited.empty()){
           int curr = visited.front();
            visited.pop();
            if(curr<0||curr>=n||cache[curr]==true) continue;
            if(arr[curr]==0) return true;
            visited.push(curr+arr[curr]);
            visited.push(curr-arr[curr]);
            cache[curr] = true;
        }
        return false;
        
      
    }
};
