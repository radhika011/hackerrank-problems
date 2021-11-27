/*
Prateek is a kindergarten teacher. He wants to give some candies to the children in his class. All the children stand in a line and each of them has a grade according to his or her performance in the class. Prateek wants to give at least one candy to each child. If two children are standing adjacent to each other, then the one with the higher rating must get more candies than the other. Prateek wants to minimize the total number of candies he must buy.
Given an array 'STUDENTS' of size 'N' that contains the grades for each student, your task is to find what is the minimum number of candies Prateek must buy so that he can distribute them among his students according to the criteria given above.




*/



int requiredCandies(vector < int > &students) {
    // Write your code here.
    int n = students.size();
    vector<int> dp(n);
    dp[0] = 1;
    for(int i = 1;i<n;i++){
        if(students[i]>students[i-1]){
            dp[i] =dp[i-1]+1;
            continue;
        }
        dp[i] = 1;
    }
    for(int j = n-2;j>=0;j--){
        if(students[j+1]<students[j]&&dp[j+1]>=dp[j]){
            dp[j] = 1+dp[j+1];
        }
    }
    int sum = 0;
    for(int i =0;i<n;i++){
        sum+=dp[i];
    }
    return sum;
    
    
    
    
}
