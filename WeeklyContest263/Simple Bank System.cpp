class Bank {
public:
    vector<long long> all_balances;
    int n;
    Bank(vector<long long>& balance) {
        all_balances = balance;
        n = all_balances.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<1||account1>n||account2<1||account2>n){
            return false;
        }
        if(all_balances[account1-1]<money){
            return false;
        }
        all_balances[account1-1]-=money;
        all_balances[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account<1||account>n) return false;
        all_balances[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account<1||account>n) return false;
        if(all_balances[account-1]<money) return false;
        all_balances[account-1]-=money;
        
        
        
        return true;
    }
};
