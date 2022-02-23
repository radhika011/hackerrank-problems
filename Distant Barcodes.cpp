/*

In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.




*/




class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        priority_queue<pair<int,int>> q;
         
        unordered_map<int,int> umap;
        for(int i = 0;i<n;i++){
            umap[barcodes[i]]++;
        }
        for(auto it = umap.begin();it!=umap.end();it++){
            q.push({it->second,it->first});
        }
       vector<int> ans;
        while(!q.empty()){
            int curr1 = q.top().second;
            int freq1 = q.top().first;
            q.pop();
            ans.push_back(curr1);
            freq1--;
            if(q.empty()) break;
             int curr2 = q.top().second;
            int freq2 = q.top().first;
            q.pop();
            ans.push_back(curr2);
            freq2--;
            if(freq1>0) q.push({freq1,curr1});
            if(freq2>0) q.push({freq2,curr2});
            
            
            
        }
        return ans;
    }
};
