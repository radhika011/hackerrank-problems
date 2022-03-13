/*

There is an n x n 0-indexed grid with some artifacts buried in it. You are given the integer n and a 0-indexed 2D integer array artifacts describing the positions of the rectangular artifacts where artifacts[i] = [r1i, c1i, r2i, c2i] denotes that the ith artifact is buried in the subgrid where:

(r1i, c1i) is the coordinate of the top-left cell of the ith artifact and
(r2i, c2i) is the coordinate of the bottom-right cell of the ith artifact.
You will excavate some cells of the grid and remove all the mud from them. If the cell has a part of an artifact buried underneath, it will be uncovered. If all the parts of an artifact are uncovered, you can extract it.

Given a 0-indexed 2D integer array dig where dig[i] = [ri, ci] indicates that you will excavate the cell (ri, ci), return the number of artifacts that you can extract.

The test cases are generated such that:

No two artifacts overlap.
Each artifact only covers at most 4 cells.
The entries of dig are unique.


*/




class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        set<pair<int,int>> digs;
        for(int i = 0;i<dig.size();i++){
            digs.insert({dig[i][0],dig[i][1]});
        }
        int ans = 0;
        for(int i =0;i<artifacts.size();i++){
            pair<int,int> currX = {artifacts[i][0],artifacts[i][1]};
            pair<int,int> currY = {artifacts[i][2],artifacts[i][3]};
            bool flag = true;
            //cout<<i<<endl;
            for(int j = currX.first;j<=currY.first;j++){
                for(int k = currX.second;k<=currY.second;k++){
                    if(digs.find({j,k})==digs.end()){
                        //cout<<j<<" "<<k<<endl;
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag){
               
                ans+=1;
            }
            
            
        }
        return ans;
    }
};
