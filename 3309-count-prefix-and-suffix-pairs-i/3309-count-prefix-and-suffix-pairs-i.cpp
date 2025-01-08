class Solution {
public:

 bool isPrefixAndSuffix(const string& str1, const string& str2) {
        if (str2.size() < str1.size()) {
                return false;
             }
    // Check if str1 is a prefix of str2
   if (str2.substr(0, str1.size()) != str1) {
     return false;
         }
                   // Check if str1 is a suffix of str2
          if (str2.substr(str2.size() - str1.size()) != str1) {
            return false;
              }
            return true;
    }

       int countPrefixSuffixPairs(const vector<string>& words) {
            int count = 0;
          for (size_t i = 0; i < words.size(); ++i) {
          for (size_t j = i + 1; j < words.size(); ++j) {
          if (isPrefixAndSuffix(words[i], words[j])) {
        count++;
                                                                                                  }
   }
}
                  return count;
 }
 
};