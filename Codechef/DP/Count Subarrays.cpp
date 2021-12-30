/*
Given an array A1,A2,...,AN, count the number of subarrays of array A which are non-decreasing.
A subarray A[i,j], where 1≤i≤j≤N is a sequence of integers Ai,Ai+1,...,Aj.

A subarray A[i,j] is non-decreasing if Ai≤Ai+1≤Ai+2≤...≤Aj. You have to count the total number of such subarrays.






*/




#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll countSubarrays(vector<ll> arr){
    int n = arr.size();
    ll sum_upto_now = 1;
    ll prev = 1;
    for(int i = 1;i<n;i++){
        ll curr = 0;
        if(arr[i]<arr[i-1]){
            curr = 1;
            prev = 1;
        }
        else{
            curr = prev+1;
            prev = curr;

        }
        sum_upto_now+=curr;
    }
    return sum_upto_now;
}



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr(n,0);
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        ll ans = countSubarrays(arr);
        cout<<ans<<endl;

    }
    return 0;
}
