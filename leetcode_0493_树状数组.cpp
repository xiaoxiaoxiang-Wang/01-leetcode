class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;
        vector<int> v = nums;
        vector<int> bit(nums.size()+1);
        sort(v.begin(),v.end()); 
        for(int i=nums.size()-1;i>=0;i--) {
            int sum_idx = upper_bound(v.begin(), v.end(), (nums[i]-1) / 2.0) - v.begin() ;
            int up_idx = upper_bound(v.begin(), v.end(), nums[i]) - v.begin();
            res+=getSum(sum_idx,bit);
            update(up_idx,bit);
        }
        return res;     
    }
    
    int getSum(int i,vector<int>& bit) {
        int sum = 0;
        while(i>0) {
            sum+=bit[i];
            i -= (i&-i);
        }
        return sum;
    }
    
    void update(int i,vector<int>& bit) {
        while(i<bit.size()) {
            bit[i]++;
            i += (i&-i);
        }
    }
};