class Solution {
    bool check(string &x1 , string &x2){
        if(x1.length() != x2.length()) return false ;
        int cnt = 0 ;
        for(int i = 0 ; i < x1.length() ; i++){
            cnt += x1[i] != x2[i] ;
            if(cnt > 1) return false ;
        }
        return cnt == 1 ;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = groups.size() ;
        vector<int> prev(n,-1); 
        vector<int> dp(n,1) ;
        int max_len = 1 , max_idx = 0 ;
        for(int i = 1 ; i < n ; i++){
            int idx = -1 ;
            for(int j = i - 1 ; j >= 0 ; j--){
                if(groups[i] != groups[j] && (idx == -1 || dp[j] > dp[idx]) && check(words[i],words[j])){
                    idx = j ;
                }
            }
            if(idx != -1) dp[i] += dp[idx] , prev[i] = idx ;
            if(dp[i] > max_len) max_len = dp[i] , max_idx = i ;
        }
        int curr = max_idx , res_idx = max_len - 1 ;
        vector<string> res(max_len) ;
        while(curr != -1){
            res[res_idx--] = words[curr] ;
            curr = prev[curr] ;
        }
        return res ;
    }
};