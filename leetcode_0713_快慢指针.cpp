class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // O(n*n)无法AC
        int size = nums.size();
        int prod = 1;
        int left = 0;
        int res = 0;
        // 可以理解为快慢指针
        for(int right=0;right<size;right++) {
            prod*=nums[right];
            while(left<=right&&prod>=k) {
                prod/=nums[left++];
            }
            res+=right-left+1;
        }

        return res;
    }
};