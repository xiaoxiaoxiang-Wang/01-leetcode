class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += '#';
		}
		vector<int> rad(t.size(), 0);
		int center = 0;
		int right = 0;
		for (int i = 1; i<t.size(); i++) {
			int left = 2 * center - i;
			rad[i] = right>i ? min(rad[left], right - i) : 1;
			while (t[i + rad[i]] == t[i - rad[i]]) {
				rad[i]++;
			}
			if (rad[i]>(right - center)) {
				center = i;
				right = i + rad[i];
			}
		}
		return s.substr((center*2-right)/2, right - center -1);
	}
};