class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int n = arr.size();
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    int diff1 = abs(arr[i]-arr[j]);
                    int diff2 = abs(arr[j]-arr[k]);
                    int diff3 = abs(arr[i]-arr[k]);
                    if(diff1<=a&&diff2<=b&&diff3<=c){
                        count++;
                    }
                }
        }
    }
        return count;
    }
};
//Another variation
int countGoodTriplets(vector<int> &arr1,vector<int> &arr2) 
{
    // Write your code here.
    int m = arr1.size();
    int n = arr2.size();
    int count = 0;
    for(int i =0;i<m;i++){
        int curr = arr1[i]*arr1[i];
        for(int j =0;j<n;j++){
            for(int k =j+1;k<n;k++){
                if(curr==(arr2[j]*arr2[k])) count++;
            }
        }
    }
    for(int i =0;i<n;i++){
        int curr = arr2[i]*arr2[i];
        for(int j =0;j<m;j++){
            for(int k =j+1;k<m;k++){
                if(curr==(arr1[j]*arr1[k])) count++;
            }
        }
    }
    return count;
}
