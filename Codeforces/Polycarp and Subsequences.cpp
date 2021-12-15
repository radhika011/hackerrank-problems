
/*
Polycarp had an array a of 3 positive integers. He wrote out the sums of all non-empty subsequences of this array, sorted them in non-decreasing order, and got an array b of 7 integers.

For example, if a={1,4,3}, then Polycarp wrote out 1, 4, 3, 1+4=5, 1+3=4, 4+3=7, 1+4+3=8. After sorting, he got an array b={1,3,4,4,5,7,8}.
Unfortunately, Polycarp lost the array a. He only has the array b left. Help him to restore the array a.

Input
The first line contains one integer t (1≤t≤5000) — the number of test cases.

Each test case consists of one line which contains 7 integers b1,b2,…,b7 (1≤bi≤109; bi≤bi+1).

Additional constraint on the input: there exists at least one array a which yields this array b as described in the statement.

Output
For each test case, print 3 integers — a1, a2 and a3. If there can be several answers, print any of them.


TWO SUM algo is not needed. Second element of b will be the second element of the array, you dumbass :)



*/




#include <cmath>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
vector<ll> getAns(vector<ll> arr){
    vector<ll> ans;
    ans.push_back(arr[0]);
    ll sum_of_two = arr[6]-arr[0];
    //cout<<"Sum of two:"<<sum_of_two<<endl;
    set<ll> cache;
    for(int i =1;i<6;i++){
        cache.insert(arr[i]);
        //cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(auto it= cache.begin();it!=cache.end();it++){
        ll curr = *it;
        if(cache.find(sum_of_two-curr)!=cache.end()){
        ans.push_back(curr);
        ans.push_back(sum_of_two-curr);
        return ans;
        }
    }
    return ans;
 
 
 
}
 
 
 
int main()
{
    int t;
    cin>>t;
 
    while(t--){
        vector<ll> arr(7,0);
        for(int i =0;i<7;i++){
            cin>>arr[i];
 
        }
 
        vector<ll> currAns = getAns(arr);
        for(int i =0;i<3;i++){
            cout<<currAns[i]<<" ";
        }
        cout<<endl;
 
 
    }
 
 
 
    return 0;
}
