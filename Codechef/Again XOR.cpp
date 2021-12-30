
/*
You may have solved a lot of problems related to XOR and we are sure that you liked them (I actually didn't bitch), so here is one more problem for you. 

You are given a binary string S of length N. Let string T be the result of taking the XOR of all substrings of size K of S. You need to find the number of 1 bits in T.

Note:

A substring is a continuous part of string which can be obtained by deleting some (may be none) character's from the beginning and some (may be none) character's from the end.
XOR of many similar-sized strings is defined here.



*/

//O(n^2)
//Can't find a O(n) approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getSet(string s,int k){
    int last = s.size()-k;
    vector<int> repo(k,0);
    for(int i = 0;i<=last;i++){
        string curr = s.substr(i,i+k);
        for(int j= 0;j<k;j++){
            if(curr[j]=='1'){
                repo[j]+=1;
            }
        }
    }
    int num = 0;
    for(int i = 0;i<k;i++){
        if(repo[i]%2!=0) num++;

    }
    return num;


}



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int setBits = getSet(s,k);
        cout<<setBits<<endl;


    }
    return 0;
}
