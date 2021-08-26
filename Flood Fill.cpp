class Solution {
public:
    void helper(int i,int j,vector<vector<int>>& image,int oldColor,int newColor,vector<vector<bool>>& visited){
        if(i>=0&&j>=0&&i<image.size()&&j<image[0].size()&&!visited[i][j]){
            visited[i][j] = true;
            if(image[i][j]==oldColor) image[i][j] = newColor;
            if((i+1)!=image.size()&&image[i+1][j]==oldColor) helper(i+1,j,image,oldColor,newColor,visited);
            if((j+1)!=image[0].size()&&image[i][j+1]==oldColor) helper(i,j+1,image,oldColor,newColor,visited);
            if((i-1)>=0&&image[i-1][j]==oldColor)helper(i-1,j,image,oldColor,newColor,visited);
            if((j-1)>=0&&image[i][j-1]==oldColor)helper(i,j-1,image,oldColor,newColor,visited);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        vector<vector<bool>> visited(image.size(),vector<bool> (image[0].size(),false));
        
        helper(sr,sc,image,oldColor,newColor,visited);
        return image;
    }
};
