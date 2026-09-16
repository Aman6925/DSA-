class Solution {
public:
    int M = 1e9+7;
    int t[1001][1001];
    //O(n * k * n)
    int solve(int n, int k, int i) {
        if (k == 0) 
            return 1;

        if (i >= n)
            return 0;

        if(t[k][i] != -1) {
            return t[k][i];
        }

        long long take = 0; //start segment from ith point
        for(int j = i+1; j <= n-1; j++) {
            take = (take + solve(n, k-1, j)) % M;
        }

        long long skip = solve(n, k, i+1) % M;

        return t[k][i] = take + skip;
    }

    int numberOfSets(int n, int k) {
        memset(t, -1, sizeof(t));
        return solve(n, k, 0) % M;
    }
};
