class Solution {
public:
    int f(string &s, int i, int n, vector<int> dp){
        if(i==n) return 0;
        
        if(dp[i] != -1) return dp[i];

        string temp="";
        int mini = INT_MAX;
        for(int j=i; j<n; j++){
            temp += s[j];
            if(ispalindrome(temp, i, j)){
                int cost = 1 + f(s, j+1, n, dp);
                mini = min(mini, cost);
            }
         
        }
        return dp[i] = mini;
    }
    bool ispalindrome(string &s, int st, int end){
        while(st<end){
            if(s[st] != s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return f(s, 0, n, dp) - 1;
    }
};