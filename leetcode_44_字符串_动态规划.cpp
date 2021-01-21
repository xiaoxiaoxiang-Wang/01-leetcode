class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
		int n = p.length();
		vector<vector<bool>> dp(m+1,vector<bool>(n+1));
		// dp[i][j]表示s的前i个字符和p的前j个字符是否匹配
		dp[0][0] = true;
        for (int i=1; i<=n; i++) {
            if(p[i-1]=='*') {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if((p[j-1]=='*'&&(dp[i-1][j]||dp[i][j-1]||dp[i-1][j-1]))||
                (dp[i-1][j-1]&&(p[j-1]=='?'||s[i-1]==p[j-1]))){
                    dp[i][j]=true;
                }
            }
        }
        return dp[m][n];
    }
};