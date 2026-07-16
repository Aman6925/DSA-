class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxx = -1;
        vector<int> pref(n);
        for(int i = 0; i < n; i++) {
            maxx = max(nums[i] , maxx);
            pref[i] = __gcd(maxx , nums[i]);
        }


      sort(pref.begin(),pref.end());
         int i = 0;
         int j  = n - 1 ; 
        long long ans  = 0;
         while(i < j) {
              ans += __gcd(pref[i] , pref[j]);
                i++;
                j--;
         }

        return ans;



    }
};