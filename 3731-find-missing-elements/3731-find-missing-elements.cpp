#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // Find the minimum and maximum values in the array
        int minVal = nums[0];
        int maxVal = nums[0];
        
        for (int num : nums) {
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
        }
        
        // Create a set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        vector<int> missing;
        
        // Iterate through the full range from min to max
        for (int i = minVal; i <= maxVal; ++i) {
            if (numSet.find(i) == numSet.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};