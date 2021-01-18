class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        // location of prev same character
        unordered_map<char, int> m;
        int rt = 0;
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            // in map
            if (m.find(s[i]) != m.end() && m[s[i]] >= index) {
                rt = rt > i - index ? rt : i - index;
                index = m[s[i]] + 1;
            }
            m[s[i]] = i;
        }
        return rt > s.length() - index ? rt : s.length() - index;
    }
};