class Solution {
    public:
        vector<string> stringMatching(vector<string>& words) {
                set<string> resultSet;
                        bool hasEmpty = false;
                                
                                        // Check for empty strings
                                                for (const string& s : words) {
                                                            if (s.empty()) {
                                                                            hasEmpty = true;
                                                                                            break;
                                                                                                        }
                                                                                                                }
                                                                                                                        
 // Include empty string if there is at least one non-empty string
                                                                                                    if (hasEmpty) {
                                                                                                     for (const string& s : words) {
                                                                                                   if (!s.empty()) {
                                                                                       resultSet.insert("");
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
 resultSet.insert(s);
         break;
                                                                                                                    }
                                                                                                                      }
                                                       }
                                                                                                                                                                           
  // Convert set to vector
                                                                                       vector<string> result(resultSet.begin(), resultSet.end());
  return result;
 }                                                                                             };