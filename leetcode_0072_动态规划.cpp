#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int length1 = word1.length();
        int length2 = word2.length();
        if(length1==0){
            return length2;
        }
        if(length2==0){
            return length1;
        }
        vector<vector<int>> dp(length1+1,vector<int>(length2+1,0));
        for(int i=0;i<length1;i++) {
          dp[i][0]=i;
        }
        for(int i=0;i<length2;i++) {
          dp[0][i]=i;
        }
        for(int i=1;i<length1+1;i++) {
          for(int j=1;j<length2+1;j++) {
            if(word1[i-1]==word2[j-1]) {
              dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j]+1,dp[i][j-1]+1));
            } else {
              dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
          }
        }
        return dp[length1][length2];
    }
};



// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int length1 = word1.length();
//         int length2 = word2.length();
//         if(length1==0){
//             return length2;
//         }
//         if(length2==0){
//             return length1;
//         }
//         vector<vector<int>> rt(length1,vector<int>(length2,0));
//         recursion(0,word1,0,word2,rt);
//         return rt[0][0];       
//     }
//     int recursion(int i1,string& word1,int i2,string& word2,vector<vector<int>>& rt) {
//       if(i1 == word1.length()) {
//         return word2.length() - i2;
//       }
//       if(i2 == word2.length()) {
//         return word1.length() - i1;
//       }
//       if(rt[i1][i2]>0) {
//         return rt[i1][i2];
//       }
//       if(word1[i1]==word2[i2]) {
//         rt[i1][i2] = recursion(i1+1,word1,i2+1,word2,rt);
//       } else {
//       //增删改  
//         int rep = recursion(i1+1,word1,i2+1,word2,rt);
//         int del = recursion(i1+1,word1,i2,word2,rt);
//         int ins = recursion(i1,word1,i2+1,word2,rt);
//         rt[i1][i2] = min(ins,min(rep,del))+1;
//       }
//       return rt[i1][i2];
//     } 
// };