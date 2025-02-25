#define mod 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int result = 0, sum = 0;
        vector<int> freq (2, 0);
        freq[0]++;  // Initialize for empty prefix sum
        
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            result += freq[!(sum % 2)]; // Use frequency of the opposite parity
            freq[sum % 2]++;            // Update current sum parity count
            result %= mod;
        }
        return result;
    }
};