class Solution {
public:
    int calculate(string s) {
        int idx = 0;
        int res = 0;
        while(idx!=s.length()) {
            res+=helper(s,idx);
        }
        return res;
    }
    // 结束一次最外层的运算
    int helper(string& s,int& idx) {
        int res = 0;
        if(idx==s.length()) {
            return res;
        }
        while(s[idx]==' ') {
            idx++;
        }
        // 优先计算括号里面
        if(s[idx]=='(') {
            idx++;
            while(s[idx]!=')') {
                res+=helper(s,idx);
            }
            idx++;
            return res;
        }

        // 一次运算
        if(s[idx]=='-') {
            return -helper(s,++idx);
        } else if(s[idx]=='+') {
            return helper(s,++idx);
        } else {
            return getValue(s,idx);
        }
    }
    int getValue(string& s,int& idx) {
        while(s[idx]==' ') {
            idx++;
        }    
        int res=0;
        for(;idx!=s.length()&&s[idx]>='0'&&s[idx]<='9';++idx) {
            res=res*10+(s[idx]-'0');
        }
        return res;
    }
};