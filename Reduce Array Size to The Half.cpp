/*
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.




*/




class Solution {
public:
    
    static bool comp(pair<int,int>& p1,pair<int,int>& p2){
        return p1.first>p2.first;
    }
    
    
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> umap;
        for(int i = 0;i<n;i++){
            if(umap.find(arr[i])==umap.end()){
                umap[arr[i]] = 1;
                continue;
            }
            umap[arr[i]]++;
        }
        vector<pair<int,int>> counts;
        for(auto it = umap.begin();it!=umap.end();it++){
            int curr = it->first;
            int freq = it->second;
            counts.push_back({freq,curr});
        }
        sort(counts.begin(),counts.end(),comp);
        
        int currSum = 0;
        int count = 0;
        int limit = round(n/2);
        for(int i = 0;i<n;i++){
            //cout<<counts[0].second<<endl;
            currSum+=counts[i].first;
            count++;
            if(currSum>=limit){
                break;
            }
        }
        return count;
    }
};
