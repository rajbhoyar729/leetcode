class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        
        // Apply shifts to the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            if (direction == 1) {
                diff[start] += 1;
                if (end + 1 < n) {
                    diff[end + 1] -= 1;
                }
            } else {
                diff[start] += 25;
                if (end + 1 < n) {
                    diff[end + 1] -= 25;
                }
            }
        }
        
        // Compute prefix sums and apply shifts
        int shift_amount = 0;
        for (int i = 0; i < n; ++i) {
            shift_amount = (shift_amount + diff[i]) % 26;
            int original = s[i] - 'a';
            int new_char = (original + shift_amount + 26) % 26; // +26 to handle negative shifts
            s[i] = 'a' + new_char;
        }
        
        return s;
    }
};