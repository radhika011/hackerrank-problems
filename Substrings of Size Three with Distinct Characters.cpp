class Solution {
public:
    int countGoodSubstrings(string s) {
        int start =0,end =0;
        vector<int> vec(26,0);
        int count =0;
        bool flag = true;
        int n = s.size();
        if(n<3) return 0;
        int i =0;
        for(;i<3;i++){
            int curr = s[i]-97;
            if(vec[curr]!=0) flag = false;
            vec[curr]++;
        }
        
        end = i-1;
        if(flag) count++;
         cout<<start<<" "<<count<<endl;
        while(end<n-1){
            flag = true;
            int startCurr = s[start]-97;
            vec[startCurr]--;
            start++;
            end++;
            int endCurr = s[end]-97;
            if(vec[endCurr]!=0) flag = false;
            vec[endCurr]++;
            for(int i =0;i<26;i++){
                if(vec[i]>1) flag = false;
            }
            if(flag) count++;
            //cout<<start<<" "<<count<<endl;
        }
        return count;
    }
};
//HashMap
class Solution {
public:
    int countGoodSubstrings(string s) {
        
//     change 3 to k to generalise
        map<char,int>mp;
        for(int i=0;i<3;i++)
            mp[s[i]]++;
        int count=0;
       
        if(mp.size()==3)
            count++;
        
        int i=0,j=2;
            while(j<s.length()-1){
            
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                
                i++;
                 j++;
                mp[s[j]]++;
               
            if(mp.size()==3)
                count++;
        }
        return count;
    }
};
