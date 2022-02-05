


/*

A generic microwave supports cooking times for:

at least 1 second.
at most 99 minutes and 99 seconds.
To set the cooking time, you push at most four digits. The microwave normalizes what you push as four digits by prepending zeroes. It interprets the first two digits as the minutes and the last two digits as the seconds. It then adds them up as the cooking time. For example,

You push 9 5 4 (three digits). It is normalized as 0954 and interpreted as 9 minutes and 54 seconds.
You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 seconds.
You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
You are given integers startAt, moveCost, pushCost, and targetSeconds. Initially, your finger is on the digit startAt. Moving the finger above any specific digit costs moveCost units of fatigue. Pushing the digit below the finger once costs pushCost units of fatigue.

There can be multiple ways to set the microwave to cook for targetSeconds seconds but you are interested in the way with the minimum cost.

Return the minimum cost to set targetSeconds seconds of cooking time.

Remember that one minute consists of 60 seconds.

Fuck this question
Look into a certain smartass 3D DP soln for this stupid BS problem

*/
class Solution {
public:
    
    int startAt, moveCost,  pushCost,  targetSeconds;
    
    int validator(string curr){
        if(curr=="") return -1;
        int n = curr.size();
        int zeros = 4-n;
        string temp = "";
        for(int i = 0;i<zeros;i++){
            temp+="0";
        }
        temp+=curr;
        //cout<<temp[1]<<endl;
        string minu = temp.substr(0,2);
        string sec = temp.substr(2,2);
       
        //cout<<minu<<" "<<sec<<endl;
        int minutes = stoi(minu);
        int seconds = stoi(sec);
        //if(seconds>60||minutes>99) return -1;
        int total = minutes*60+seconds;
        if(total!=targetSeconds) return -1;
        int prev = startAt;
        int cost = 0;
        for(int i = 0;i<curr.size();i++){
            int dig = curr[i]-'0';
            if(prev==dig){
                cost+=pushCost;
                continue;
            }
            cost+=moveCost;
            cost+=pushCost;
            
            prev = dig;
        }
        return cost;
    }
    
    
    void helper(string curr,int digits,int& minimum){
        
        if(digits==4){
            int cost = validator(curr);
            if(cost==-1) return;
             if(cost<minimum){
            minimum = cost;
            //cout<<curr<<" "<<cost<<endl;
        }
            return;
        }
        for(int i = 0;i<=9;i++){
            string temp = curr;
            helper(curr+to_string(i),digits+1,minimum);
        }
        int cost = validator(curr);
        if(cost==-1) return;
        if(cost<minimum){
            minimum = cost;
           //cout<<curr<<" "<<cost<<endl;
        }
        
    }
    
      int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        this->startAt = startAt;
        this->moveCost = moveCost;
        this->pushCost = pushCost;
        this->targetSeconds = targetSeconds;
        int minimum = INT_MAX;
        helper("",0,minimum);
        return minimum;
    }
};
