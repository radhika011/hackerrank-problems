//HOW TO SEPERATE STRING BY SPACES
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    vector<string> names;
    while(!cin.fail()){
        string s;
        cin>>s;
        names.push_back(s);
    }
    map<string,int> counts;
    for(int i =0;i<names.size();i++){
        counts[names[i]]++;
    }
    bool flag = false;
    auto it = counts.begin();
    
    while(it!=counts.end()){
        if(it->second>=2){
            flag = true;
            cout<<it->first<<" "<<it->second<<endl;
        }
        
        it++;
    }
    if(!flag) cout<<-1<<endl;

    return 0;
    
    
}
