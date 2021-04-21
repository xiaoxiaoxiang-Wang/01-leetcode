class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();
        vector<int> dp(lenB+1);
        int res = 0;
        for(int i=0;i<lenA;i++) {
            for(int j=lenB-1;j>=0;j--) {
                if(A[i]==B[j]) {
                    dp[j+1] = dp[j]+1;
                    res = max(dp[j+1],res);
                } else {
                    dp[j+1] = 0;
                }
            }
        }
        return res;
    }
};