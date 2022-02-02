
/*
There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. The answers of the students are represented by a 2D integer array students where students[i] is an integer array that contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).

Each student will be assigned to one mentor, and each mentor will have one student assigned to them. The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then their compatibility score is 2 because only the second and the third answers are the same.
You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.

Given students and mentors, return the maximum compatibility score sum that can be achieved.


*/




class Solution {
public:
    
    int helper(vector<vector<int>>& scores,set<int>& visited,int curr){
        int m = scores.size();
        if(curr==m) return 0;
        int maxSum = 0;
        for(int i =0;i<m;i++){
            //set<int> temp = visited;
            if(visited.find(i)==visited.end()){
                //temp.insert(i);
                visited.insert(i);
                int currSum = scores[curr][i]+helper(scores,visited,curr+1);
                maxSum = max(currSum,maxSum);
                auto it = visited.find(i);
                visited.erase(it);
            }
        }
        return maxSum;
    }
    
    
    
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<vector<int>> scores(m,vector<int>(m,0));
        for(int i = 0;i<m;i++){
            vector<int> currStudent = students[i];
            for(int j =0;j<m;j++){
                vector<int> currMentor = mentors[j];
                int currScore = 0;
                for(int k =0;k<n;k++){
                    currScore+=(currStudent[k]==currMentor[k]);
                }
                scores[i][j] = currScore;
                //cout<<scores[i][j]<<" ";
            }
            //cout<<endl;
        }
        set<int> visited;
        int ans = helper(scores,visited,0);
        return ans;
        
        
        
        
    }
};
