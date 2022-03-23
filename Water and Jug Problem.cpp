/*

You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount of water supply available. Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.


*/




class Solution {
public:
    
    set<pair<int,int>> visited; 
    int targetCapacity;
    bool ans;
    int jug1Capacity, jug2Capacity;
    Solution(){
        ans = false;
    }
    void helper(int currX,int currY,int steps){
        if(steps>pow(10,6)) return;
        if(ans) return;
        if(visited.find({currX,currY})!=visited.end()) return;
        if((currX+currY)==targetCapacity||currX==targetCapacity||currY==targetCapacity){
            ans = true;
            return;
        }
        visited.insert({currX,currY});
        //if(currX+currY<targetCapacity) return;
        //cout<<currX<<" "<<currY<<endl;
        
        steps++;
        helper(currX,0,steps);
        helper(0,currY,steps);
        if(currX!=jug1Capacity) helper(jug1Capacity,currY,steps);
        if(currY!=jug2Capacity) helper(currX,jug2Capacity,steps);
         if((currX+currY)>=jug2Capacity&&currX>0) helper(currX-(jug2Capacity-currY),jug2Capacity,steps);
        if((currX+currY)>=jug1Capacity&&currY>0)  helper(jug1Capacity,currY-(jug1Capacity-currX),steps);
        if((currX+currY)<jug1Capacity&&currY>0)  helper(currX+currY,0,steps);
        if((currX+currY)<jug2Capacity&&currX>0)  helper(0,currX+currY,steps);
        
    }
    
    
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        this->targetCapacity = targetCapacity;
        this->jug1Capacity = jug1Capacity;
        this->jug2Capacity = jug2Capacity;
        if((jug1Capacity+jug2Capacity)<targetCapacity) return false; //IMPORTANT
        helper(jug1Capacity,jug2Capacity,0);
        return ans;
    }
};
