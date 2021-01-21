//#include <algorithm>    // std::sort
//#include <vector>
//using namespace std;
//
//
//bool Less(const vector<int>& v1, const vector<int>& v2)
//{
//	return v1[0] < v2[0]; //从小到大排序
//}
//
//class Solution {
//public:
//	vector<vector<int>> merge(vector<vector<int>>& intervals) {
//		sort(intervals.begin(), intervals.end(), Less);
//		vector<vector<int>> rt;
//		if (intervals.size()) {
//			rt.push_back(intervals[0]);
//		}
//		else {
//			return rt;
//		}
//		for (int i = 1; i < intervals.size(); i++) {
//			if (rt.back()[1] < intervals[i][0]) {
//				rt.push_back(intervals[i]);
//			}
//			else if (rt.back()[1] < intervals[i][1]) {
//				rt.back()[1] = intervals[i][1];
//			}
//		}
//		return rt;
//	}
//};