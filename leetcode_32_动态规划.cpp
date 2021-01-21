class Solution {
public:
    int longestValidParentheses(string s) {
        int rt=0;
        int length = s.length();
        // dp[i]表示以i结尾的最长子串
        vector<int> dp(s.length(),0);
        for(int i=1;i<length;i++) {
            if(s[i]==')'&&(i-dp[i-1]-1>=0)&&s[i-dp[i-1]-1]=='(') {
                dp[i]=dp[i-1]+2;
                if(i-dp[i-1]-2>0) {
                    dp[i]+=dp[i-dp[i-1]-2];
                }
                rt = dp[i]>rt?dp[i]:rt;
            }
        }
        return rt;
    }
};