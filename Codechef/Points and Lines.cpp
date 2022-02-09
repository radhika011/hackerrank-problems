


/*


Given N points of the form (xi,yi) on a 2-D plane.

From each point, you draw 2 lines one horizontal and one vertical. Now some of the lines may overlap each other, therefore you are required to print the number of distinct lines you can see on the plane.

Note:

Two horizontal lines are distinct if they pass through different y coordinates.
Two vertical lines are distinct if they pass through different x coordinates.
*/

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
        unordered_set<int> xis;
        unordered_set<int> yis;
        while(n--){
            int x,y;
            cin>>x>>y;
            xis.insert(x);
            yis.insert(y);
        }
        cout<<(xis.size()+yis.size())<<endl;


    }
    return 0;
}
