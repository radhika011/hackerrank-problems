
/*

You are given an integer N where N≤10. Consider any array A with length N where each element can either be 0, 1, or 2, we define f(A) as the number of extrema in A. You need to find the sum of f(A) over all possible arrays A.

Note:

In an array A, we consider Ai as an extremum if it is strictly greater than both of its neighbors (i.e. Ai>Ai−1 and Ai>Ai+1), or if it is strictly smaller than both of its neighbors (i.e. Ai<Ai−1 and Ai<Ai+1). Note that first and last elements are not counted as extremum.
Extrema is the plural of extremum.


*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getSum(int i, int n, vector<int> currState){
    if(i==n) {
        int num = 0;
        for(int i = 1;i<n-1;i++){
            if(currState[i]>currState[i-1]&&currState[i]>currState[i+1]||
                currState[i]<currState[i-1]&&currState[i]<currState[i+1]){
                    num+=1;

                }


        }
        return num;

    }
    currState[i] = 0;
    int option1 = getSum(i+1,n,currState);
    currState[i] = 1;
    int option2 = getSum(i+1,n,currState);
    currState[i] = 2;
    int option3 = getSum(i+1,n,currState);
    return option1+option2+option3;



}



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> currState(n,0);
        int ans = getSum(0,n,currState);
        cout<<ans<<endl;

    }
    return 0;
}
