class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        unordered_set<int> uset;
        for(int i =0;i<array.size();i++){
            uset.insert(array[i]);
        }
        for(int i =1;i<=n;i++){
            if(uset.find(i)==uset.end()){
                return i;
            }
        }
        return -1;
    }
};
