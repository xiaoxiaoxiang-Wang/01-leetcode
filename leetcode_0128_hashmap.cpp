class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> nums_map;
        for(int i=0;i<nums.size();i++) {
            nums_map.insert(make_pair(nums[i],false));
        }
        int rt=0;
        for(auto iter=nums_map.begin();iter!=nums_map.end();iter++) {
            if(!iter->second) {
                int num_minu = iter->first-1;
                int num_plus = iter->first+1;
                while(find_num(nums_map,num_minu)) {
                    num_minu--;
                }
                while(find_num(nums_map,num_plus)) {
                    num_plus++;
                }
                rt=max(rt,num_plus-num_minu-1);
            }         
        }
        return rt;
    }
    bool find_num(unordered_map<int,bool>& nums_map,int& num) {
        auto a = nums_map.find(num);
        if(a!=nums_map.end()) {
            a->second = true;
            return true;
        }
        return false;
    }
};