
/*

The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance:

The MEX of [2,2,1] is 0 because 0 does not belong to the array.
The MEX of [3,1,0,1] is 2 because 0 and 1 belong to the array, but 2 does not.
The MEX of [0,3,1,2] is 4 because 0,1,2 and 3 belong to the array, but 4 does not.
You're given an array A containing 2⋅N integers where 0≤Ai≤N. Is it possible to reorder the elements of the array in such a way that the MEX of the first N elements is equal to the MEX of the last N elements?


*/

//We only need to check if the freq of any element is 1 before getting mex


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int> counts;
        for(int i = 0;i<(2*n);i++){
            int curr;
            cin>>curr;
            counts[curr]+=1;
        }
        bool flag = true;
        int odds = 0;
        for(int i = 0;i<=n;i++){
            if(counts.find(i)==counts.end()){
                cout<<"YES"<<endl;
                flag = false;
                break;
            }
            int freq = (counts.find(i))->second;
            //cout<<i<<" "<<freq<<endl;
            if(freq==1){
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
            if(freq%2!=0){
                odds++;
            }
        }

        if(flag){
           cout<<"YES"<<endl;
        }


    }
    return 0;
}
