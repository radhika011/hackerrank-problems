/*


A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.






*/





class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int ans = 0;
        // Substring = T
        int rem = k;
        int start = 0;
        int end = 0;
        while(end<n){
            if(answerKey[end]=='T'){
                
                ans = max(ans,end-start+1);
                end++;
                continue;
            }
            if(rem==0){
                int i = start;
                for(;i<end;i++){
                    if(answerKey[i]=='F') break;
                }
                start = i+1;
                rem++;
                ans = max(ans,end-start+1);
                continue;
            }
            else{
                rem--;
                ans = max(ans,end-start+1);
                end++;
            }
        }
        
        
        
        
        rem = k;
        start = 0;
        end = 0;
        while(end<n){
            if(answerKey[end]=='F'){
                
                ans = max(ans,end-start+1);
                end++;
                continue;
            }
            if(rem==0){
                int i = start;
                for(;i<end;i++){
                    if(answerKey[i]=='T') break;
                }
                start = i+1;
                rem++;
                ans = max(ans,end-start+1);
                continue;
            }
            else{
                rem--;
                ans = max(ans,end-start+1);
                end++;
            }
        }
        
        
        return ans;
        //Substring = F
    }
};
