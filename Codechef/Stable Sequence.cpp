/*

Life is change, change is stability. 
Chef calls a sequence of integers A1,A2,…,AN stable if all the elements in the sequence are equal.

Chef gives you a sequence A1,A2,…,AN. You may perform the following operations on the sequence any number of times (possibly 0):

Select any prefix A[1…k] such that max(A[1…k])=A[k] and set A[i]:=A[k] ∀i∈[1,k−1]. For example, if the sequence A=[3,1,4,5,9], then choosing k=3 yields the sequence [4,4,4,5,9].

Select any segment A[L…R] and shift the segment cyclically to the left keeping other elements unchanged. For example, if the sequence A=[3,4,1,5,9], then choosing L=2 and R=4 yields the sequence [3,1,5,4,9].

Chef is asking you to find the minimum number of operations required to make the sequence stable.

It is guaranteed that you can always make the sequence stable using such operations.



*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int getMinOps(vector<int> ans,int n){
    int maxVal = ans[0];
    int maxInd = 0;
    int minVal = ans[0];
    for(int i =1;i<n;i++){
        if(ans[i]>=maxVal){
            maxVal = ans[i];
            maxInd = i;
        }
        if(ans[i]<=minVal){
            minVal = ans[i];
        }
    }
    if(maxVal==minVal) return 0;
    if(maxInd==n-1) return 1;
    return 2;
}



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ans(n);
        for(int i =0;i<n;i++){
            cin>>ans[i];
        }
        int minOps = getMinOps(ans,n);
        cout<<minOps<<endl;

    }
    return 0;
}
