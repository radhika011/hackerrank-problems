//Binary Search
#include<bits/stdc++.h>
using namespace std;
void getLargestMinDist(vector<int> stalls,int c){
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int end = stalls[n-1]-stalls[0];
    int d = 1;
    int start = 0;
    bool flag = false;
    while(start<=end){
        //cout<<start<<" "<<end<<endl;
        int mid = (start+end)/2;
        d =mid;
        int currCount = c;
        currCount--;
        int currPos = 0;
        while(currCount!=0){
        	flag = false;
            int k = currPos+1;
            for(;k<n;k++){
                if(stalls[k]-stalls[currPos]>=d){
                    flag = true;
                    break;
                }
            }
            currPos = k;
            if(!flag) break;
            currCount--;
        }
        if(currCount!=0){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    if(!flag) cout<<d-1<<endl;
    else cout<<d<<endl;
}

int main(){
    // write your code
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> stalls;
        while(n--){
            int curr;
            cin>>curr;
            stalls.push_back(curr);
        }
        getLargestMinDist(stalls,c);
        
        
        
        
    }
    
    
    
    
    return 0;
}
