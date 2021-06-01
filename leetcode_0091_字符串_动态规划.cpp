class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len+1,0);
        dp[len-1]=s[len-1]>'0'?1:0;
        dp[len]=1;
        for(int i=len-2;i>=0;i--) {
            if(s[i]=='1'||s[i]=='2'&&s[i+1]<='6') {
                dp[i]=dp[i+1]+dp[i+2];              
            } else if(s[i]>='2'){
                dp[i]=dp[i+1];
            }
        }
        return dp[0];
    }
};