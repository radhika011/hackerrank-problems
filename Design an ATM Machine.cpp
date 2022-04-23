/*

There is an ATM machine that stores banknotes of 5 denominations: 20, 50, 100, 200, and 500 dollars. Initially the ATM is empty. The user can use the machine to deposit or withdraw any amount of money.

When withdrawing, the machine prioritizes using banknotes of larger values.

For example, if you want to withdraw $300 and there are 2 $50 banknotes, 1 $100 banknote, and 1 $200 banknote, then the machine will use the $100 and $200 banknotes.
However, if you try to withdraw $600 and there are 3 $200 banknotes and 1 $500 banknote, then the withdraw request will be rejected because the machine will first try to use the $500 banknote and then be unable to use banknotes to complete the remaining $100. Note that the machine is not allowed to use the $200 banknotes instead of the $500 banknote.
Implement the ATM class:

ATM() Initializes the ATM object.
void deposit(int[] banknotesCount) Deposits new banknotes in the order $20, $50, $100, $200, and $500.
int[] withdraw(int amount) Returns an array of length 5 of the number of banknotes that will be handed to the user in the order $20, $50, $100, $200, and $500, and update the number of banknotes in the ATM after withdrawing. Returns [-1] if it is not possible (do not withdraw any banknotes in this case).



*/




typedef long long ll;
class ATM {
public:
    unordered_map<ll,ll> notes1; 
    ATM() {
        notes1[20] = 0;
        notes1[50] = 0;
        notes1[100] = 0;
        notes1[200] = 0;
        notes1[500] = 0;
    }
    
    void deposit(vector<int> banknotesCount) {
        notes1[20] += banknotesCount[0];
        notes1[50] += banknotesCount[1];
        notes1[100] += banknotesCount[2];
        notes1[200] += banknotesCount[3];
        notes1[500] += banknotesCount[4];
    }
    
    int helper(int amount,vector<int>& ans,unordered_map<ll,ll>& notes){
        if(amount==0) return 0;
        if(amount<20) return -1;
        if(amount>=500&&notes[500]!=0){
            int d1 = amount/500;
            if(notes[500]<d1){
               int diff = d1-notes[500];
               int rem = amount-(notes[500]*500);
               ans[4]+=notes[500];
                notes[500] = 0;
                //cout<<ans[4]<<" "<<notes[500]<<endl;
               return helper(rem,ans,notes);
            }
            int rem = amount-(d1*500);
            ans[4]+=d1;
            notes[500] -= d1;
            return helper(rem,ans,notes);
        }
        if(amount>=200&&notes[200]!=0){
            int d1 = amount/200;
            if(notes[200]<d1){
                int diff = d1-notes[200];
               int rem = amount-(notes[200]*200);
               ans[3]+=notes[200];
                 notes[200] =0;
               return helper(rem,ans,notes);
            }
            int rem = amount-(d1*200);
            ans[3]+=d1;
            notes[200] -= d1;
            return helper(rem,ans,notes);
        }
        if(amount>=100&&notes[100]!=0){
            int d1 = amount/100;
            if(notes[100]<d1){
                int diff = d1-notes[100];
               int rem = amount-(notes[100]*100);
               ans[2]+=notes[100];
                 notes[100]=0;
               return helper(rem,ans,notes);
            }
            int rem = amount-(d1*100);
            ans[2]+=d1;
            notes[100] -= d1;
            return helper(rem,ans,notes);
        }
        if(amount>=50&&notes[50]!=0){
            int d1 = amount/50;
            if(notes[50]<d1){
                int diff = d1-notes[50];
               int rem = amount-(notes[50]*50);
               ans[1]+=notes[50];
                 notes[50]=0;
               return helper(rem,ans,notes);
            }
            int rem = amount-(d1*50);
            ans[1]+=d1;
            notes[50] -= d1;
            return helper(rem,ans,notes);
        }
            int d1 = amount/20;
            if(notes[20]<d1) return -1;
            int rem = amount-(d1*20);
            ans[0]+=d1;
            return helper(rem,ans,notes);
        
        
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
        if(amount%10!=0) return {-1};
        unordered_map<ll,ll> notes = notes1;
        int res = helper(amount,ans,notes);
        for(int i =0;i<5;i++){
            //cout<<ans[i]<<" ";
        }
        //cout<<endl;
        if(res==-1){
            return {-1};
        }
        
        notes1[20]-=ans[0];
        notes1[50]-=ans[1];
        notes1[100]-=ans[2];
        notes1[200]-=ans[3];
        notes1[500]-=ans[4];
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
