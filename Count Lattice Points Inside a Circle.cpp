/*

Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number of lattice points that are present inside at least one circle.

Note:

A lattice point is a point with integer coordinates.
Points that lie on the circumference of a circle are also considered to be inside it.



*/
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> visited;
        int n = circles.size();
        for(int i =0;i<n;i++){
            int r = circles[i][2];
            int x1 = circles[i][0]+r;
            int x2 = circles[i][0]-r;
            int y1 = circles[i][1]+r;
             int y2 = circles[i][1]-r;
            //cout<<x1<<" "<<x2<<endl;
            for(int j = x2;j<=x1;j++){
                for(int k = y2;k<=y1;k++){
                    
                    if((pow(j-circles[i][0],2)+pow(k-circles[i][1],2))<=pow(r,2)){
                        if(visited.find({j,k})==visited.end()){
                           
                            visited.insert({j,k});
                        }
                    }
                }
            }
            
        }
        return visited.size();
    }
};
