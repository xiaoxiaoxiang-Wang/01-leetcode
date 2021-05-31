class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3]={0};
        for(int num:nums) {
            counts[num]++;
        }
        int idx = 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<counts[i];j++) {
                nums[idx++]=i;
            }             
        }
    }
};