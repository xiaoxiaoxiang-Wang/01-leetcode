#include<string>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.length();
		int n = p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
		// dp[i][j]表示s的前i个字符和p的前j个字符是否匹配
		dp[0][0] = true;
		// p>0匹配s==0,判断偶数*结尾
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0) {
				dp[0][i] = dp[0][i - 2] && p[i - 1] == '*';
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				// 当前j-1不为*
				if (p[j - 1] != '*' || j == 1) {
					dp[i][j] = dp[i - 1][j - 1] && isMatch(s[i - 1], p[j - 1]);
				}
				else {
					// *和前一个字符作为整体 s现在的也和p以前的匹配
					dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && isMatch(s[i - 1], p[j - 2]));
				}
			}
		}
		return dp[m][n];
	}

	bool isMatch(char& a, char& b) {
		return a == b || b == '.';
	}
};