
/*

You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.
Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.




*/




class Solution {
public:
    
    unordered_map<int,Employee*> mapper;
    
    int helper(int curr){
        
       // if((mapper[curr]->subordinates).size()==0) return 
        int ans = mapper[curr]->importance;
        vector<int> subs = mapper[curr]->subordinates;
        for(int i = 0;i<subs.size();i++){
            ans+=helper(subs[i]);
        }
        return ans;
    }
    
    
    int getImportance(vector<Employee*> employees, int id) {
        
        int n = employees.size();
        for(int i = 0;i<n;i++){
            mapper[employees[i]->id] = employees[i];
        }
        return helper(id);
    }
};
