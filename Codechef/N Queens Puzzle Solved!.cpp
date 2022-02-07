/*

Chef, being a Chess fan, was thrilled after he read the following news:

Michael Simkin, a postdoctoral fellow at Harvard University’s Center of Mathematical Sciences and Applications proved that for a large value of N, there are approximately (0.143⋅N)N configurations in which N queens can be placed on a N×N chessboard so that none attack each other.

Although the formula is valid for large N, Chef is interested in finding the value of function f(N) = (0.143⋅N)N for a given small value of N. Since Chef is busy understanding the proof of the formula, please help him calculate this value.

Print the answer rounded to the nearest integer. That is, if the actual value of f(N) is x,

Print ⌊x⌋ if x−⌊x⌋<0.5
Otherwise, print ⌊x⌋+1
where ⌊x⌋ denotes the floor of x.


*/




#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double ans = 0.143*n;
        ans = pow(ans,n);
        cout<<round(ans)<<endl;

    }
    return 0;
}
