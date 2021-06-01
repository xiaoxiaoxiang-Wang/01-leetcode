#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// BFS
class Solution {
private:
  string s1_;
  string s2_;
  string s3_;
  unordered_set<int> us;
public:
    bool isInterleave(string s1, string s2, string s3) {
      if(s1.size()+s2.size()!=s3.size()) {
          return false;
      }
      queue<int> q{{0,0}};
      unordered_set<int> s;
      int s1_index=0;
      int s2_index=0; 
      int i3=0;
      while(!q.empty()&&i3<s3.size()) {
        int q_length = q.size();
        for(int i=0;i<q_length;i++) {
          int top = q.front();
          q.pop();
          int i1=top/s3.size();
          int i2=top%s3.size();
          if(i1<s1.size()&&s1[i1]==s3[i3]) {
            int key = (i1+1)*s3.size()+i2;
            if(!s.count(key)) {
              q.push(key);
              s.insert(key);
            }
          }
          if(i2<s2.size()&&s2[i2]==s3[i3]) {
            int key = i1*s3.size()+i2+1;
            if(!s.count(key)) {
              q.push(key);
              s.insert(key);
            }
          }
        }
        i3++;
      }
      return !q.empty()&&i3==s3.size();
    }

};

// DFS + set??????
// class Solution {
// private:
//   string s1_;
//   string s2_;
//   string s3_;
//   unordered_set<int> us;
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         s1_ = s1;
//         s2_ = s2;
//         s3_ = s3;
//         return dfs(0,0,0);
//     }
//     bool dfs(int i1,int i2,int i3) {
//       int key = i1*s3_.size()+i2;
//       if(us.count(key)) {
//         return false;
//       }
//       if(i1==s1_.length()&&i2==s2_.length()&&i3==s3_.length()) {
//         return true;
//       }

//       if(i1<s1_.length()&&s1_[i1]==s3_[i3]) {
//         if(dfs(i1+1,i2,i3+1)) {
//           return true;
//         }
//       }
//       if(i2<s2_.length()&&s2_[i2]==s3_[i3]) {
//         if(dfs(i1,i2+1,i3+1)) {
//           return true;
//         }
//       }
//       us.insert(key);
//       return false;
//     }
// };


// DP
// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3)
//     {
//         if (s1.length() + s2.length() != s3.length()) {
//             return false;
//         }
//         vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1));
//         dp[0][0] = true;
//         for (int i = 1; i <= s1.length(); i++) {
//             dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
//         }
//         for (int j = 1; j <= s2.length(); j++) {
//             dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
//         }
//         for (int i = 1; i <= s1.length(); i++) {
//             for (int j = 1; j <= s2.length(); j++) {
//                 dp[i][j] =
//                     (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
//             }
//         }
//         return dp[s1.length()][s2.length()];
//     }
// };