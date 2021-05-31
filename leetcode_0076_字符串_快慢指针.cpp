class Solution {
public:
    string minWindow(string s, string t) {
        int begin=0,gap=INT_MAX,cnt=0,left=0;
        int ascii[128]={0};
        for(char c:t){
            ascii[c]++;
        }
        for(int i=0;i<s.length();i++) {
            // 发现t里面有的元素
            // 未匹配上的-1等于-1
            if(--ascii[s[i]]>=0) {
                cnt++;
            }
            // 完成了一次匹配
            while(cnt==t.length()) {
                // left表示慢指针
                if(gap>i-left) {
                    gap = i-left;  
                    begin = left;
                }
                // 未匹配上的+1继续等于0
                // 匹配上的等于1
                if (++ascii[s[left]] > 0) {
                    --cnt;
                } 
                ++left;
            }
        }

        return gap == INT_MAX?"":s.substr(begin,gap+1);
    }
};