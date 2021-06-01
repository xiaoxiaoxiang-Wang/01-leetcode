#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int diff = s.length()-t.length()+1;
        vector<vector<long>> dp(t.length()+1,vector<long>(diff+1,0));
        for(int j=1;j<diff+1;j++) {
            dp[0][j]=1;
        }
        for(int i=1;i<t.length()+1;i++) {
            for(int j=1;j<diff+1;j++) {
                if(t[i-1]==s[i-1+j-1]) {
                  dp[i][j]=dp[i][j-1]+dp[i-1][j];
                } else {
                  dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[t.length()][diff];
    }
};

// class Solution {
// private: unordered_set<int> us; 
// public:
//     int numDistinct(string s, string t) {
//       int num = 0;
//       // 缓存
//       vector<vector<int>> vv(s.length(),vector<int>(t.length(),-1));
//       for(int i=0;i<s.length()-t.length() + 1;i++) {
//         // 从起点开始对比
//         if(s[i] == t[0]) {
//           num+=bfs(s,i+1,t,1,vv);
//         }
//       }
//       return num;
//     }
//     int bfs(string& s, int i, string& t,int j,vector<vector<int>>& vv) {
//       if(j==t.length()) {
//         return 1;
//       }
//       if(i==s.length()) {
//         return 0;
//       }
//       if(vv[i-1][j-1]>-1) {
//         return vv[i-1][j-1];
//       }
//       int num = 0;
//       if(s[i]==t[j]){
//         vv[i][j] = bfs(s,i+1,t,j+1,vv);
//         num+=vv[i][j];
//       } 
//       vv[i][j-1] = bfs(s,i+1,t,j,vv);
//       return num + vv[i][j-1];     
//     }
// };

    //     int numDistinct(string s, string t) {
    //   // vv[i][j]表示0-i包含0-j的数量
    //   // 转移方程，结尾相同和不同
    //   // ************s[i]!=s[j]****s[i]==s[j]
    //   // vv[i][j] == vv[i][j-1] + vv[i-1][j-1]
    //   // i=0时，vv[i][j]=1;
    //   vector<vector<int>> vv(t.length()+1,vector<int>(s.length()+1,0));
    //   for(int j=0;j<s.length()+1;j++) {
    //     vv[0][j] = 1;
    //   }
    //   for(int i=1;i<t.length()+1;i++) {
    //     for(int j=1;j<s.length()+1;j++) {
    //         vv[i][j] = vv[i][j-1]+s[i]==s[j]?vv[i-1][j-1]:0;
    //     }
    //   }
    //   return vv[t.length()][s.length()];
    // }

