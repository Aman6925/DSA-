class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            int newMax = max({curr, maxProd * curr, minProd * curr});
            int newMin = min({curr, maxProd * curr, minProd * curr});

            maxProd = newMax;
            minProd = newMin;

            ans = max(ans, maxProd);
        }

        return ans;
    }
};