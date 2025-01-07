class Solution {
    public:
        bool isMatch(string s, string p) {
                int len_s = s.length();
                        int len_p = p.length();
                                vector<bool> dp(len_p + 1, false);
                                        dp[0] = true; // empty pattern matches empty string

                                                // Handle patterns with '*' at the beginning
                                                        for (int j = 1; j <= len_p; j++) {
                                                                    if (p[j - 1] == '*') {
                                                                                    dp[j] = dp[j - 1];
                                                                                                }
                                                                                                        }

                                                                                                                for (int i = 1; i <= len_s; i++) {
                                                                                                                            bool prev = dp[0];
                                                                                                                                        dp[0] = false; // empty pattern doesn't match non-empty string

                                                                                                                                                    for (int j = 1; j <= len_p; j++) {
                                                                                                                                                                    bool temp = dp[j];
                                                                                                                                                                                    if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                                                                                                                                                                                                        dp[j] = prev;
                                                                                                                                                                                                                        } else if (p[j - 1] == '*') {
                                                                                                                                                                                                                                            dp[j] = dp[j - 1] || dp[j];
                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                                dp[j] = false;
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                prev = temp;
                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                                                                            return dp[len_p];
                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                };
