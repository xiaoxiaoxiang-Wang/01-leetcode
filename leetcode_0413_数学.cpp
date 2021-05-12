class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) {
            return 0;
        }
        int diff = nums[1] - nums[0];
        int len = 0;
        int res = 0;
        for(int i=2;i<nums.size();i++) {
            if(nums[i]-nums[i-1] == diff) {
                len++;
            } else {
                res += len*(len+1)/2;
                len = 0;
                diff = nums[i]-nums[i-1];
            }
        }
        res += len*(len+1)/2;
        
        return res;
    }
};