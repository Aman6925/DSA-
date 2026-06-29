class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> counts(128, 0); 
        
        int low = 0;
        int max_count = 0; 
        int max_len = 0;
        
        for (int high = 0; high < n; high++) {
            counts[s[high]]++;
            max_count = max(max_count, counts[s[high]]);
            
            while ((high - low + 1) - max_count > k) {
                counts[s[low]]--;
                low++;
            }
            
            max_len = max(max_len, high - low + 1);
        }
        
        return max_len;
    }
};
    
