
/*
You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

Constraints - 3<=n<=100 
Brute Force works :)


*/



class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        set<int> temp;
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k =0;k<n;k++){
                    if(digits[i]!=0&&digits[k]%2==0&&i!=j&&j!=k&&i!=k){
                        int curr = digits[i]*100+digits[j]*10+digits[k];
                        temp.insert(curr);
                    }
                }
            }
        }
        for(auto it = temp.begin();it!=temp.end();it++){
            ans.push_back(*it);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
