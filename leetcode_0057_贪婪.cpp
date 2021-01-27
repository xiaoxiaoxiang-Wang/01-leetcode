class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        int i = 0;
        vector<vector<int>> rt;
        for(;i<intervals.size();i++) {
            if(newInterval[0]<=intervals[i][0]) {
                left = newInterval[0];
                break;
            } else if(newInterval[0]<=intervals[i][1]){
                left = intervals[i][0];
                break;
            }
            rt.push_back(intervals[i]);
        }
        
        for(;i<intervals.size();i++) {
            if(newInterval[1]<intervals[i][0]) {
                right = newInterval[1];
                break;
            } else if(newInterval[1]<=intervals[i][1]){
                right = intervals[i][1];
                i++;
                break;
            }
        }
        rt.push_back({left,right});
        for(;i<intervals.size();i++) {
            rt.push_back(intervals[i]);
        }
        return rt;
    }
};