class Solution {
public:
    string smallestNumber(string pattern) {
        const int n=pattern.size();
        string ans(n+1, '0');
        for(int i=0, succD=0; i<=n; i++){
            while(i<n && pattern[i]=='D'){
                succD++;
                i++;
            }
            char c=i+'1';
            for(int j=0; j<=succD; j++)
                ans[i-j]=c-succD+j;
            succD=0;
        }
        return ans;
    }
};