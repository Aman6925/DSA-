class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = n*n;
        int evenSum = n*(n+1);
        int result;
        result = __gcd(oddSum,evenSum);

        return result;

        
    }
};