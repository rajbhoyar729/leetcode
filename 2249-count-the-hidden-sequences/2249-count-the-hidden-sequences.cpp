class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
                long long prefix = 0, maxPrefix = 0, minPrefix = 0;

                        for (int diff : differences) {
                                    prefix += diff;
                                                maxPrefix = max(maxPrefix, prefix);
                                                            minPrefix = min(minPrefix, prefix);
                                                                    }

                                                                            long long validLower = lower - minPrefix;
                                                                                    long long validUpper = upper - maxPrefix;

                                                                                            return max(0LL, validUpper - validLower + 1);
                                                                                                }
                                                                                                };