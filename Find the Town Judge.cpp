


/*

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts_someone(n,0);
        int n_edges = trust.size();
        for(int i = 0;i<n_edges;i++){
            trusts_someone[trust[i][0]-1] = 1;
        }
        int p_judge = -1;
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(!flag&&trusts_someone[i]==0) {
                p_judge = i;
                flag = true;
            }
            else if(flag&&trusts_someone[i]==0) return -1;
        }
        if(p_judge==-1) return -1;
        p_judge+=1;
        //cout<<p_judge<<endl;
        vector<int> is_trusted(n,0);
        for(int i = 0;i<n_edges;i++){
            if(trust[i][1]==p_judge){
                is_trusted[trust[i][0]-1] = 1;
            }
        }
        for(int i =0;i<n;i++){
            if(is_trusted[i]!=1&&i!=p_judge-1) return -1;
        }
        return p_judge;
    }
};
//WTH WAS THAT? smh I could've just calculated the indegree and outdegree for each vertex
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        int n_edges = trust.size();
        for(int i =0;i<n_edges;i++){
            int from = trust[i][0];
            int to = trust[i][1];
            indegree[to]++;
            outdegree[from]++;
        }
        for(int i =1;i<=n;i++){
            if(indegree[i]==(n-1)&&outdegree[i]==0) return i;
        }
        return -1;
    }
};
