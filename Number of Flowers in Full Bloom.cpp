/*

You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array persons of size n, where persons[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.



*/




class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start;
        vector<int> end;
        for(int i =0;i<flowers.size();i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        vector<int> ans;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(int i =0;i<persons.size();i++){
            int starter = upper_bound(start.begin(),start.end(),persons[i])-start.begin();
            int ender = lower_bound(end.begin(),end.end(),persons[i])-end.begin();
            //cout<<starter<<" "<<ender<<endl;
            ans.push_back(starter-ender);
        }
        return ans;
    }
};
