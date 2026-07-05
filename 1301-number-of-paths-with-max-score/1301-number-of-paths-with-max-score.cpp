class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> t;

    int getIntFromChar(char ch) {
        return ch != 'S' && ch != 'E' ? ch - '0' : 0;
    }

    bool isValid(int i, int j, vector<string>& board) {
        return (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X');
    }

    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E') {
            return {0, 1};
        }
        if (board[i][j] == 'X') {
            return {0, 0};
        }

        if (t[i][j] != make_pair(-1, -1)) {
            return t[i][j];
        }

        int upScore = -1, upPaths = 0;
        int leftScore = -1, leftPaths = 0;
        int diagScore = -1, diagPaths = 0;

        char ch = board[i][j];

        if (isValid(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            if (paths > 0) {
                upScore = score + getIntFromChar(ch);
                upPaths = paths;
            }
        }

        if (isValid(i, j - 1, board)) {
            auto [score, paths] = solve(i, j - 1, board);
            if (paths > 0) {
                leftScore = score + getIntFromChar(ch);
                leftPaths = paths;
            }
        }

        if (isValid(i - 1, j - 1, board)) {
            auto [score, paths] = solve(i - 1, j - 1, board);
            if (paths > 0) {
                diagScore = score + getIntFromChar(ch);
                diagPaths = paths;
            }
        }

        int bestScore = max({upScore, leftScore, diagScore});
        if (bestScore == -1)
            return t[i][j] = {0, 0};

        int bestPaths = 0;
        if (upScore == bestScore) bestPaths = (bestPaths + upPaths) % MOD;
        if (leftScore == bestScore) bestPaths = (bestPaths + leftPaths) % MOD;
        if (diagScore == bestScore) bestPaths = (bestPaths + diagPaths) % MOD;

        return t[i][j] = {bestScore, bestPaths};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        t.assign(n, vector<pair<int, int>>(n, {-1, -1}));

        pair<int, int> result = solve(n - 1, n - 1, board);

        if (result.second == 0)
            return {0, 0};

        return {result.first, result.second};
    }
};