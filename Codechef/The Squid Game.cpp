
/*
"Let the games begin."

Squid Game has become a blockbuster hit and the frontman is now finding it difficult to accommodate all the participants in Squid Game 2.0. So, he decided that he will allow only those participants who could solve the following problem.

There are a total of N players who are competing in the Squid Game, numbered from 1 to N. When the ith player gets eliminated from the game, Ai amount of money is added to the prize pool. The game is played until N−1 players get eliminated, and the only player left is declared as the winner. The winner gets all the money present in the prize pool.

You are given an array A consisting of N elements, where Ai denotes the prize money added to the prize pool when the ith player gets eliminated from the game. Find the maximum prize that the winner can get, given that you can choose any player to be the winner.





*/



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int sum = 0;
	    vector<int> arr(n,0);
	    for(int i =0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    cout<<(sum-arr[0])<<endl;
	}
	return 0;
}
