class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
       sort(nums.begin() , nums.end());

       int smallest = nums[0];
       int largest = nums[n-1];

       return __gcd(smallest,largest); 
    }
};