/*
A string S is called Chef's favourite if every substring chef in S must have a substring code before it.

You are given a string S of size N that contains both code and chef as a substring. Please determine if S is Chef's favourite.

Note: A substring is a continuous part of string which can be obtained by deleting some (may be none) character's from the beginning and some (may be none) character's from the end.



*/




#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool flag = true;
        while(s.find("chef")!=string::npos){
            int ind = s.find("chef");
            //cout<<ind<<endl;
            if(ind<4){
                flag = false;
                break;
            }
            if(s.find("code")!=string::npos){
                int prev_ind = s.find("code");
                if(prev_ind>ind){
                    flag = false;
                    break;
                }
                else{
                    break;
                }
            }
            s = s.substr(ind+4,n);
            //cout<<s<<endl;

        }

        if(flag) cout<<"AC"<<endl;
        else cout<<"WA"<<endl;


    }
    return 0;
}
