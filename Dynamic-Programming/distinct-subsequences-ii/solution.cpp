class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int mod = 1e9+7;

        vector<int> endwithchar(26, 0);
        int sum=0;
    
        for(int i=0; i<n; i++){
            int idx = s[i]-'a';

            int curr = (1 + sum - endwithchar[idx] + mod) % mod;

            sum = (sum + curr) % mod;

            endwithchar[idx] = (endwithchar[idx] + curr) % mod;
        }
        return sum;
    }
};