class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(( nums[i]%nums[j]==0|| nums[j]%nums[i]==0 ) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            
        }
        int maxval=dp[0];
        int maxidx=-1;
        for(int i=1; i<n; i++){
            if(dp[i]>maxval){
                maxval = dp[i];
                maxidx = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[maxidx]);
        int curr = hash[maxidx];

        while(curr != -1){
            temp.push_back(nums[curr]);
            curr = hash[curr];
        }
        reverse(temp.begin(), temp.end());

        return temp;
    }
};