class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        // second表示差为first的以当前位置为结尾的序列的数量
        vector<unordered_map<int,int>> dp(size);
        for(int i=1;i<size;i++) {
            for(int j=0;j<i;j++) {
                long diff = (long)nums[i]-nums[j];
                if(diff>INT_MAX || diff < INT_MIN){
                    continue;
                }
                dp[i][diff]++;
                if (dp[j].count(diff)) {
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return res;
    }
};