
/*
Alex has ‘N’ badminton players in his squad whose heights are given in an array ‘alex’. Rome has ‘M’ badminton players in her squad whose heights are given in an array ‘rome’. They want to choose one player from each squad to represent their college in badminton championships. The managing committee has asked them to send two players such that the absolute difference in their heights is minimum. Help them find the minimum height difference they can achieve if they choose one player from each squad.
Note: Both the arrays are given in a non-decreasing manner.
Example: Let alex = [1, 2, 5, 7] and rome = [5, 8, 10]. If Alex chooses the third person and Rome chooses the first person, the height difference would be 0, which is the minimum we can achieve.


*/


int optimalDuo(vector<int> &alex, vector<int> &rome){
    // Write your code here.
    int i =0;
    int j =0;
    int minDiff = INT_MAX;
    while(i<alex.size()&&j<rome.size()){
        if(abs(alex[i]-rome[j])<minDiff){
            minDiff = abs(alex[i]-rome[j]);
        }
        if(alex[i]<rome[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return minDiff;
    
}
