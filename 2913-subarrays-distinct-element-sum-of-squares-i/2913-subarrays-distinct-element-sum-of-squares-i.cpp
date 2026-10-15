class Solution {
public:
    int sumCounts(vector<int>& nums) {
         int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> freq(101, 0);   // nums[i] <= 100
            int distinct = 0;

            for (int j = i; j < n; ++j) {
                if (freq[nums[j]]++ == 0) {
                    ++distinct;          // new value seen in nums[i..j]
                }
                ans += 1LL * distinct * distinct;
            }
        }

        return ans;
        
    }
};