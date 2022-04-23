/*

You are given an integer total indicating the amount of money you have. You are also given two integers cost1 and cost2 indicating the price of a pen and pencil respectively. You can spend part or all of your money to buy multiple quantities (or none) of each kind of writing utensil.

Return the number of distinct ways you can buy some number of pens and pencils.


*/





typedef long long ll;
class Solution {
public:
   
    
    
    
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll ans = 0;
        ll maxPens = total/cost1;
        for(int i= 0;i<=maxPens;i++){
            ll rem = total-(cost1*i);
            ll pencilChoices = rem/cost2;
            pencilChoices+=1;
            ans+=pencilChoices;
            
        }
        return ans;
    }
};
