class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        vector<int> vec;
        while(n!=0){
            int rem = n%10;
            n = n/10;
            vec.push_back(rem);
        }
        bool changed = false;
        int ind = -1;
        for(int i = 0;i<vec.size();i++){
            if(vec[i]==6){
                ind = i;
                changed = true;
                
            }
        }
        
        if(!changed) return num;
        vec[ind] = 9;
        int offset = pow(10,(vec.size()-1));
        int newNum = 0;
        for(int i = vec.size()-1;i>=0;i--){
            
            newNum += vec[i]*offset;
            
            offset = offset/10;
        }
        return newNum;
        
    }
};
