
/*
You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.




*/







class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.size();
        vector<int> counts(10,0);
        for(int i = 0;i<n;i++){
            counts[num[i]-'0']++;
        }
       
        string p1 = "";
        for(int i = 9;i>=0;i--){
            if(i==0&&p1=="") break;
            if(counts[i]>=2){
                int quo = counts[i]/2;
                for(int j = 0;j<quo;j++){
                    p1+=to_string(i);
                }
                counts[i]-=(quo*2);
            }
        }
        
        int midele = -1;
        for(int i = 9;i>=0;i--){
            if(counts[i]>=1){
                midele = i;
                break;
            }
             //cout<<"here"<<endl;
        }
       
        string ans = p1;
        if(midele!=-1)ans+=to_string(midele);
        reverse(p1.begin(),p1.end());
        ans+=p1;
        return ans;
    }
};
