class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int freq[101] = {0};

        for(int x : nums) {
            freq[x] = 1;
        }

        for(int multiple = k; ; multiple += k) {
            if(multiple > 100 || freq[multiple] == 0) {
                return multiple;
            }
        }
    }
};