class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = 0;
        for(int i=0;i<nums.size();i++) {
            left = max(left,nums[i]);
            right+=nums[i];
        }  
        
        
        while(left<right) {
            //right是可取值，则left和right相邻取更小的值
            int mid = (left+right)/2;
            int cnt = 0;
            int sum = 0;
            for(int i=0;i<nums.size();i++) {
                if(sum+nums[i]>mid) {
                    sum = nums[i];
                    cnt++;
                } else {
                    sum += nums[i];
                }
            }

            // mid值不可取
            if(cnt>=m) {
                left = mid+1;
            } else{
                right = mid;
            } 
        }
        
        return left;
    }
};