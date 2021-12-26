
/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

USE A MAX HEAP, CONTRARY TO INTUITION 
MIN HEAP WOULD ALSO WORK



*/




class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> q;
        int n = points.size();
        for(int i = 0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            q.push({x*x+y*y,x,y});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i =0;i<k;i++){
            vector<int> curr = q.top();
            q.pop();
            curr.erase(curr.begin());
            ans.push_back(curr);
        }
        return ans;
    }
};
