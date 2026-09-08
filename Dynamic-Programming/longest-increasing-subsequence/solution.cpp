// solution 1 => using recursion and memorization.
class Solution1{
public:
    int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (i == n)
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + f(i + 1, i, nums, dp);
        }
        int nonTake = f(i + 1, prev, nums, dp);

        return dp[i][prev + 1] = max(take, nonTake);
    }
    int LISrecurseSolution(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};

// solution 2 => using tabulation print LIS.
class Solution2 {
public:
    int printOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> idx(n, -1);

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    idx[i]=j;
                }
            }
        }

        vector<int>temp;
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(dp[maxi] < dp[i]){
                maxi = i;
            }
        }

        temp.push_back(nums[maxi]);
        int curr=-1;
        while(curr != -1){
        temp.push_back(nums[curr]);
        curr = idx[curr];
        }
        reverse(temp.begin(), temp.end());
        // temp hold LIS print

        // thats return lenght of LIS
        return dp[maxi];
    }
};

// solution 3 => using binary serach lower bound function
// TC => O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        temp.push_back(nums[0]); 
        int len=1;

        for(int i=1; i<n; i++){
          if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
            len++;
          }
          else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];             
          }
        }
        return len;
    }
};

