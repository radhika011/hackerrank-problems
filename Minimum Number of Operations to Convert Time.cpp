/*
You are given two strings current and correct representing two 24-hour times.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

In one operation you can increase the time current by 1, 5, 15, or 60 minutes. You can perform this operation any number of times.

Return the minimum number of operations needed to convert current to correct.



*/





class Solution {
public:
    int convertTime(string current, string correct) {
        int hx = stoi(current.substr(0,2));
        int mx = stoi(current.substr(3,5));
        int x = hx*60+mx;
        int hy = stoi(correct.substr(0,2));
        int my = stoi(correct.substr(3,5));
        int y = hy*60+my;
        int diff = y-x;
        int ans = 0;
        if(diff>=60){
            
        ans+=(diff/60);
        diff = diff%60;
           
        if(diff==0) return ans;
            
        }
        if(diff>=15){
          ans+=(diff/15);
        diff = diff%15;
             if(diff==0) return ans;
        }
        if(diff>=5){
       
          ans+=(diff/5);
        diff = diff%5;
            
        if(diff==0) return ans;
        }
        
          ans+=(diff/1);
        diff = diff%1;
        return ans;
        
        
        
    }
};
