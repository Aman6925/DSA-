class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int MAX = *max_element(nums.begin(), nums.end());

        
        vector<long long> freq(MAX + 1, 0);

        for (int x : nums)
            freq[x]++;

        
        vector<long long> cnt(MAX + 1, 0);

        for (int g = 1; g <= MAX; g++) {
            for (int multiple = g; multiple <= MAX; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }

       
        vector<long long> exact(MAX + 1, 0);

        for (int g = MAX; g >= 1; g--) {

            
            exact[g] = cnt[g] * (cnt[g] - 1) / 2;

            
            for (int multiple = 2 * g; multiple <= MAX; multiple += g) {
                exact[g] -= exact[multiple];
            }
        }

        
        vector<long long> prefix(MAX + 1, 0);

        for (int g = 1; g <= MAX; g++) {
            prefix[g] = prefix[g - 1] + exact[g];
        }

        
        vector<int> ans;

        for (long long q : queries) {

            
            int gcdValue =
                lower_bound(prefix.begin() + 1,
                            prefix.end(),
                            q + 1)
                - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};