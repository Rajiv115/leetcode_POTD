class Solution {
public:
 int f(int p1,int p2,string &s1,string &s2,vector<vector<int>>&dp){
        if(p1 == s1.length() || p2 == s2.length())return 0;
        if(dp[p1][p2] != -1)return dp[p1][p2];
        if(s1[p1] == s2[p2])return dp[p1][p2] = 1 + f(p1+1,p2+1,s1,s2,dp);
        else{
            return dp[p1][p2] = max(f(p1+1,p2,s1,s2,dp),f(p1,p2+1,s1,s2,dp));
        }
    }

    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        int temp = f(0,0,s,s2,dp);
        return s.length() - temp;
    }
};