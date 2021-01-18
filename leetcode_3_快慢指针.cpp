#include <map>
using std::map;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.length()<1) {
			return 0;
		}
		map<char, int> m;
		m[s[0]] = 0;
		int rt = 1;
		int index = 0;
		for (int i = 1; i<s.length(); i++) {
			if (m.find(s[i]) != m.end()) {
				rt = rt>m.size() ? rt : m.size();
				int k = m[s[i]];
				for (int j = index; j <= k; j++) {
					m.erase(s[j]);
				}
				index = k+1;
			}
			m[s[i]] = i;
		}
		return rt>m.size() ? rt : m.size();     
    }
};