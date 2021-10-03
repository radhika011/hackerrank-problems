class Solution {
public:
    int balancedStringSplit(string s) {
        int lcount = 0;
        int rcount=0;
        int count = 0;
        int len = s.size();
        for(int i =0;i<len;i++){
            if(s[i]=='R') rcount++;
            else if(s[i]=='L') lcount++;
            if(rcount==lcount){
                count++;
                rcount = 0;
                lcount =0;
            }
        }
        return count;
    }
};
