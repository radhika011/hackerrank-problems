/*


You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.


*/






class Solution {
public:
    int largestInteger(int num) {
        vector<int> odds;
        vector<int> evens;
        string temp = to_string(num);
        for(int i =0;i<temp.size();i++){
            int curr = temp[i]-'0';
            if(curr%2!=0) odds.push_back(curr);
            else evens.push_back(curr);
        }
        sort(odds.begin(),odds.end(),greater<int>());
        sort(evens.begin(),evens.end(),greater<int>());
        string ans = "";
        int oddptr = 0;
        int evenptr = 0;
        for(int i =0;i<temp.size();i++){
            int curr = temp[i]-'0';
            if(curr%2!=0) ans+=odds[oddptr++]+'0';
            else ans+=evens[evenptr++]+'0';
        }
        return stoi(ans);
    }
};
