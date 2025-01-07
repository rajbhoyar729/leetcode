class Solution {
    public:
        vector<string> stringMatching(vector<string>& words) {
        set<string> result;
         bool hasEmpty = false;
                                
       // Check for empty strings
          for (const string& s : words) {
           if (s.empty()) {
         hasEmpty = true;
            break;        }
                                                                                                                }
    // Include empty string if there is at least one non-empty string
                                                                                                    if (hasEmpty) {
                                                                                                   for (const string& s : words) {
                                                                                                    if (!s.empty()) {
                                                                                                                                                                                        result.insert("");
                                                                                                                                                                                                            break;
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                        }
        }
                                                                                                                                                                                                                                     
     // Sort words by length ascendingly
                                                                                      vector<string> sortedWords = words;
                                                                                                                                                                                                sort(sortedWords.begin(), sortedWords.end(), [](const string& a, const string& b) {
                                                                                                                                                                                                                                                                                            return a.length() < b.length();
                                                                                                                                                                                                                                                                                                    });
                                                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                                                                    // Check for substring relationships
                                                                                                                                                                                                                                                                                                                            for (size_t i = 0; i < sortedWords.size(); ++i) {
                                                                                                                                                                                                                                                                                                                                        const string& s = sortedWords[i];
                                                                                                                                                                                                                                                                                                                                                    for (size_t j = i + 1; j < sortedWords.size(); ++j) {
                                                                                                                                                                                                                                                                                                                                                                    const string& t = sortedWords[j];
                                                                                                                                                                                                                                                                                                                                                                                    if (t.find(s) != string::npos) {
                                                                                                                                                                                                                                                                                                                                                                                                        result.insert(s);
                                                                                                                                                                                                                                                                                                                                                                                                                            break;
                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                          return vector<string>(result.begin(), result.end());
                                                                                                        }
                        };
