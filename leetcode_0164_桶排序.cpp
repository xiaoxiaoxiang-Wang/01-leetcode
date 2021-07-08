#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
      int size = nums.size();
      if(size ==0) {
          return 0;
      }
      int mx = INT32_MIN;
      int mn = INT32_MAX;
      for(int i=0;i<nums.size();i++) {
        mx = max(mx,nums[i]);
        mn = min(mn,nums[i]);
      }
      // 每个桶区间的大小
      int bucketCap = (mx-mn)/nums.size()+1;
      vector<int> mxVector(size,INT32_MIN);
      vector<int> mnVector(size,INT32_MAX);
      for(int num:nums) {
        int index = (num-mn)/bucketCap;
        mxVector[index] = max(mxVector[index],num);
        mnVector[index] = min(mnVector[index],num);
      }
      int res = 0;
      int pre = 0;
      for(int i=0;i<size;i++) {
        //最大值必然出现在前后两个桶之间
        if(mnVector[i]!=INT32_MAX) {
          res = max(res,mnVector[i]-mxVector[pre]);
          pre = i;
        }
      }
      return res;
    }
};