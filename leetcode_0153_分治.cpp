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
      if(right-left<=1) {
        return nums[right];
      }
      int mid = (left+right)/2;
      if(nums[mid]>nums[left]) {
        return find(mid,right,nums);
      } else {
        return find(left,mid,nums);
      }
    }
};