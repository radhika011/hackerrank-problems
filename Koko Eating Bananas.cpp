
/*

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 





*/










typedef long long ll;
class Solution {

    vector<int> piles;
    
   private: 

    ll hoursRequired(ll speed)
    {
        ll cnt = 0;
        for(int c: piles)
        {
            cnt += c/speed + (c % speed != 0);
        }
        return cnt;
    }

public:
    int minEatingSpeed(vector<int>& piles, int H) {
        this->piles = piles;
    	const int n = (int)piles.size();

    	int maxElement = 0;

    	for (int i = 0; i < n; ++i)
    	{
    		maxElement = max(maxElement, piles[i]);
    	}
        
        int ans = -1, low = 1;
        ll high = maxElement;	// Max element in the array

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            ll timeRequired = hoursRequired(mid);		// Hours required to eat all bananas with speed as 'mid'
            if(timeRequired <= H)		// Condition has evaluated to true
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
        
    };
