/*
There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 





*/




class Solution {
public:
    
    static bool comp(pair<string,int> p1,pair<string,int> p2){
        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
    
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        q.push(id);
        int currLevel = 0;
        set<int> visited;
        visited.insert(id);
        while(currLevel!=level){
            currLevel++;
            int temp = q.size();
            for(int i = 0;i<temp;i++){
                int curr = q.front();
                q.pop();
                for(int j = 0;j<friends[curr].size();j++){
                    if(visited.find(friends[curr][j])==visited.end()){
                        q.push(friends[curr][j]);
                        visited.insert(friends[curr][j]);
                    }
                }
            }
        }
        unordered_map<string,int> counts;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 0;i<watchedVideos[curr].size();i++){
                counts[watchedVideos[curr][i]]++;
            }
        }
        vector<pair<string,int>> temp;
        for(auto it = counts.begin();it!=counts.end();it++){
            temp.push_back({it->first,it->second});
        }
        sort(temp.begin(),temp.end(),comp);
        vector<string> ans;
        for(int i = 0;i<temp.size();i++){
            ans.push_back(temp[i].first);
        }
        return ans;
        
    }
};
