class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        vector<deque<int>> vec(26);
        for(int i=0;i<s.length();i++) {
            int idx = s[i]-'A';
            if(!vec[idx].empty()&&i-vec[idx].front()-vec[idx].size()>k) {
               vec[idx].pop_front(); 
            }
            vec[idx].push_back(i);
            if(k+vec[idx].size()>res) {
                res = k+vec[idx].size();
            }
        }
        
        return res>s.length()?s.length():res;
    }
};