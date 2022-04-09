/*

BS

*/





vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    int lastAnswer = 0;
    vector<int> answers;
    vector<vector<int>> arr(n,vector<int>(0,0));
    int idx = -1;
    for(int i = 0;i<queries.size();i++){
        int op = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        if(op==1){
            idx = ((x^lastAnswer)%n);
            arr[idx].push_back(y);
        }
        else{
            idx = ((x^lastAnswer)%n);
            lastAnswer = arr[idx][y%arr[idx].size()];
            answers.push_back(lastAnswer);
        }
    }
    return answers;
}
