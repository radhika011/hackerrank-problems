/*
Nitin and Sobhagya were playing a game with coins. If Sobhagya has more coins then he is winning, otherwise Nitin is winning. Note that this means if both Nitin and Sobhagya have the same number of coins, then Nitin is winning.

Initially Nitin has A coins while Sobhagya has B coins. Then Ritik came and gave his C coins to the player who is not winning currently, after which Satyarth came and repeated the same process (gave his D coins to the player who is not winning currently).

Find the final winner of the game.

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;





int main()
{
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll n = a;
        ll s = b;
        if(n<s) n+=c;
        else s+=c;
        if(n<s) n+=d;
        else s+=d;
        if(n>=s){
            cout<<"N"<<endl;
            continue;
        }
        cout<<"S"<<endl;

    }
    return 0;
}





