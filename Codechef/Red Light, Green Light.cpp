/*

“You won’t get caught if you hide behind someone.”

Sang-Woo advises Gi-Hun to hide behind someone to avoid getting shot.

Gi-Hun follows Sang-Woo's advice and hides behind Ali, who saved his life earlier. Gi-Hun and Ali both have the same height, K. Many players saw this trick and also started hiding behind Ali.

Now, there are N players standing between Gi-Hun and Ali in a straight line, with the ith player having height Hi. Gi-Hun wants to know the minimum number of players who need to get shot so that Ali is visible in his line of sight.

Note:

Line of sight is a straight line drawn between the topmost point of two objects. Ali is visible to Gi-Hun if nobody between them crosses this line.
Even if there are some players who have the same height as that of Gi-Hun and Ali, Ali will be visible in Gi-Hun's line of sight.
Gi-Hun and Ali have the same height.

SO EASY BUT SUCH A COOL QUESTION


*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> people(n,0);
	    int toShoot = 0;
	    for(int i =0;i<n;i++){
	        cin>>people[i];
	        if(people[i]>k){
	            toShoot++;
	        }
	    }
	    cout<<toShoot<<endl;
	    
	}
	return 0;
}
