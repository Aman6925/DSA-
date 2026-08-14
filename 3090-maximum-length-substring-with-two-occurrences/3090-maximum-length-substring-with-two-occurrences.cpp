class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.length();
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            vector<int>arr(26, 0);
            for(int j = i; j < n; j++) {
                if(++arr[s[j] - 'a'] == 3) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        
        return maxLen;
    }
};