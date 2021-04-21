class Solution {
public:
    int numPermsDISequence(string S) {
        int size = S.length();
        vector<vector<int>> dp(size+1,vector<int>(size+1,0));
        dp[0][0] = 1;
        // dp[i][j] 表示以j结尾的序列，i个数的排列数量
        for(int i=1;i<=size;i++) {
            if(S[i-1]=='I') {
                for(int j=1;j<=i;j++) {
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%1000000007;
                }
            } else {
                for(int j=i-1;j>=0;j--) {
                    dp[i][j] = (dp[i][j+1] + dp[i-1][j])%1000000007;
                }
            }
        }
        int res = 0;
        for(int i=0;i<=size;i++) {
            res = (res+dp[size][i])%1000000007;
        }
        return res;
    }
};