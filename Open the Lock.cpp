/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.





*/




class Solution {
public:
    
    void dfs(string curr, queue<string>& q,int ind,unordered_set<string>& deadends){
        if(ind==curr.size()) return;
        int position = curr[ind]-'0';
        string sp1 = curr;
        sp1[ind] = ((position+1)%10)+'0';
        string sp2 = curr;
        if(position==0) sp2[ind] = 9+'0';
        else sp2[ind] = ((position-1)%10)+'0';
       // cout<<curr[ind]<<" "<<sp1[ind]<<" "<<sp2[ind]<<endl;
        if(deadends.find(sp1)==deadends.end()){
            q.push(sp1);
        }
         if(deadends.find(sp2)==deadends.end()){
            q.push(sp2);
        }
        dfs(curr,q,ind+1,deadends);
    }
    
    
    
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        unordered_set<string> deads{deadends.begin(),deadends.end()};
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        int steps = 0;
        while(!q.empty()){
            int temp = q.size();
            for(int i =0;i<temp;i++){
                string curr = q.front();
                q.pop();
                if(curr==target) return steps;
                if(visited.find(curr)!=visited.end()||deads.find(curr)!=deads.end()) continue;
                dfs(curr,q,0,deads);
                visited.insert(curr);
            }
            //cout<<q.size()<<endl;
            
            steps++;
        }
        
        return -1;
        
    }
};
