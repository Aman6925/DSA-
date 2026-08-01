class Solution {
public:
    int n;
    vector<vector<int>> t; // Use vector for safety instead of fixed array

    int solve(vector<int>& nums, int l, int r) {
        if(l > r) return 0;
        if(l == r) return nums[l];
        if(t[l][r] != -1) return t[l][r];

        int take_left  = nums[l] + min(solve(nums, l+2, r), solve(nums, l+1, r-1));
        int take_right = nums[r] + min(solve(nums, l, r-2), solve(nums, l+1, r-1));

        return t[l][r] = max(take_left, take_right);
    }

    // Change this name to all lowercase 'predictTheWinner'
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        t.assign(n, vector<int>(n, -1)); // Initialize dynamically

        int total = 0;
        for(int x : nums) total += x; // Manual sum to avoid include issues if any

        int player1 = solve(nums, 0, n-1);
        int player2 = total - player1;

        return player1 >= player2;
    }
};