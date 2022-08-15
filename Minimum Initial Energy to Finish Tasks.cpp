/*
You are given an array tasks where tasks[i] = [actuali, minimumi]:

actuali is the actual amount of energy you spend to finish the ith task.
minimumi is the minimum amount of energy you require to begin the ith task.
For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.

You can finish the tasks in any order you like.

Return the minimum initial amount of energy you will need to finish all the tasks.






*/







class Solution {
public:
    
    
    
    static bool sorter(vector<int>& v1,vector<int>& v2){
        return (v1[1]-v1[0])>(v2[1]-v2[0]);
    }
    
    bool check(vector<vector<int>>& tasks,int curr){
        for(int i = 0;i<tasks.size();i++){
            if(curr<=0) return false;
            if(tasks[i][1]>curr) return false;
            curr-=tasks[i][0];
        }
        if(curr<0) return false;
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(),tasks.end(),sorter);
        int low = 1;
        int high = 0;
        for(int i =0;i<n;i++){
            high+=tasks[i][1];
        }
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(tasks,mid)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }
        return ans;
        
    }
};
