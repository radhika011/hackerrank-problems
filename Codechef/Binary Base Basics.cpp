
/*

You are given a binary string S and an integer K. In one operation, you can pick any bit and flip it, i.e turn 0 to 1 or 1 to 0. Can you make the string S a palindrome using exactly K operations?

Print YES if this is possible, and NO if it is not.

*/


#include <iostream>

using namespace std;

bool canConvert(string s,int k){
    bool ans = true;
    int n = s.size();
    int i = 0;
    int j = n-1;
    while(i<=j){
        char ch1 = s[i];
        char ch2 = s[j];
        if(ch1!=ch2){
            if(k==0){
                ans = false;
                break;
            }
            k--;
        }
        i++;
        j--;
    }
    
    if(k%2!=0) ans = false;
    if(n%2!=0&&k%2!=0) ans = true;
    return ans;

}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool ans = canConvert(s,k);
        if(ans==1){
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;


    }
    return 0;
}
