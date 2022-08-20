
/*


You are given a binary string s. In one second, all occurrences of "01" are simultaneously replaced with "10". This process repeats until no occurrences of "01" exist.

Return the number of seconds needed to complete this process.



*/










class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int ans = 0;
        while(true){
            int found = -1;
            for(int i = 0;(i+1)<n;i++){
                if(s[i]=='0'&&s[i+1]=='1'){
                    s[i] = '1';
                    s[i+1] = '0';
                    found = 1;
                    i++;
                }
               
            }
             //cout<<s<<endl;
            if(found==-1) return ans;
            ans++;
        }
        return -1;
    }
};
