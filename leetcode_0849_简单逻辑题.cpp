class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int i = 0;
		while (!seats[i++]);
		int res = i - 1;
		int begin = i - 1;
		int size = seats.size();
		for (; i<size; i++) {
			if (seats[i]) {
				res = max((i - begin) / 2, res);
                begin = i;
			}
		}
		return max(size - begin - 1, res);
	}
};