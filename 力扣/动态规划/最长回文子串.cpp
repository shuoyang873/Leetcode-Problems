/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1)return s;
        if(n==2){
            if(s[0]==s[1])return s;
            else{
                string ans="";
                ans+=s[0];
                return ans;
            }
        }
        int begin=0,max_len=1;           //这边注意这个最大长度初始是1
        vector<vector<bool>>dp(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<n;i++){
                int j=i+l-1;
                if(j>=n){
                    break;
                }
                if(s[i]==s[j]){
                    if(j-i<3){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        begin=i;
                    }
                }
            }
        }
        return s.substr(begin,max_len);
    }
};
// @lc code=end

