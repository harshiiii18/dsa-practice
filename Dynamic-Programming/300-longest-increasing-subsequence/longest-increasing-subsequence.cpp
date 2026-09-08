class Solution {
public:
    int f(int i, int prev, vector<int>& nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(i==n) return 0;
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int take = 0;
        if(prev==-1 || nums[i] > nums[prev]){
            take = 1 + f(i+1, i, nums, dp);
        }
        int nonTake = f(i+1, prev, nums, dp);

        return dp[i][prev+1] = max(take, nonTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};