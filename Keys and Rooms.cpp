class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int top = q.front();
            //cout<<top<<endl;
            q.pop();
            vector<int> currKeys = rooms[top];
            for(int i =0;i<currKeys.size();i++){
                if(!visited[currKeys[i]]){
                visited[currKeys[i]] = true;
                q.push(currKeys[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
        
    }
};
