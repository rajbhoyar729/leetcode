class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        int a = 0;

        for (char x = 'a'; x <= 'z'; ++x) {
            // Find the first occurrence of x
            int l = s.find(x);
            if (l == std::string::npos) continue;

            // Find the last occurrence of x
            int r = s.rfind(x);
            if (l >= r) continue;

            std::unordered_set<char> seen;
            int t = 0;

            for (int i = l + 1; i < r; ++i) {
                if (seen.find(s[i]) == seen.end()) {
                    seen.insert(s[i]);
                    t++;
                    if (t == 26) break; // Early termination if all unique y's are found
                }
            }

            a += t;
        }

        return a;
    }
};