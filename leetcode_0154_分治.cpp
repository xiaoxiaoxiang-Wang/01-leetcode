#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[nums.size()-1]>nums[0]) {
            return nums[0];
        }
        return find(0,nums.size()-1,nums);
    }
    int find(int left,int right,vector<int>& nums) {
      if(left>=right) {
        return nums[left];
      }
      int mid = (left+right)/2;
      if(nums[mid]>nums[right]) {
        return find(mid+1,right,nums);
      } else if(nums[left]>nums[mid]){
        return find(left+1,mid,nums);
      } else {
        return min(find(mid+1,right,nums),find(left,mid-1,nums));
      }
    }
};