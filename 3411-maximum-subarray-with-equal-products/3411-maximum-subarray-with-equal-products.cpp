class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        // Possible prime factors because nums[i] <= 10
        vector<int> primes = {2, 3, 5, 7};

        int ans = 1;

        // Try every starting index
        for (int i = 0; i < n; i++) {

            vector<int> sum(4, 0);
            vector<int> mn(4, INT_MAX);
            vector<int> mx(4, 0);

            // Extend the subarray
            for (int j = i; j < n; j++) {

                int x = nums[j];

                // Calculate prime factorization
                for (int k = 0; k < 4; k++) {
                    int p = primes[k];
                    int cnt = 0;

                    while (x % p == 0) {
                        cnt++;
                        x /= p;
                    }

                    sum[k] += cnt;
                    mn[k] = min(mn[k], cnt);
                    mx[k] = max(mx[k], cnt);
                }

                // Check product equivalent condition
                bool valid = true;

                for (int k = 0; k < 4; k++) {
                    if (sum[k] != mn[k] + mx[k]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};