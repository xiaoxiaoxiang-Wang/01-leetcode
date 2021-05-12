class Solution {
public:
    int findKthNumber(int n, int k) {
        if(n<=9){
            return k;
        }
        // n的每一位数字
        vector<int> digits;
        // 1,11,111...
        vector<int> ones {1};
        
        int a = n;
        while(a>0) {
            digits.push_back(a%10);
            a/=10;
            ones.push_back(ones.back()*10+1);
        }
        
        // 减一方便索引
        int s = digits.size() - 1;
        // n去掉首位后的值
        int m = n-digits[s]*pow(10,s)+1;
        // 用于while循环
        int idx = s-1;
        int res = 0;
        
        int b = 0;
        int ext = 0;
        for(int i=s-1;i>=0;i--) {
            b = b*10 + digits[i];
            ext += b+1;
        }
        
        if(k<=(digits[s]-1)*ones[s]) {
            res = (k-1)/ones[s]+1;
            k =(k-1)%ones[s];
        } else if(k<=(digits[s]-1)*ones[s]+ones[s-1]+m) {
            res = digits[s];
            k = (k-1)%ones[s];
            if(k>ext) {
                k = k -m;
                idx--;
            }
        } else {
            k -= (digits[s]-1)*ones[s]+ones[s-1]+m;
            res = (k-1)/ones[s-1]+digits[s]+1;
            k = (k-1)%ones[s-1];
            idx--;
        }
        while(k!=0) {
            res = res*10+(k-1)/ones[idx];
            k = (k-1)%ones[idx];
            idx--;
        }
        
        return res;
    }
};