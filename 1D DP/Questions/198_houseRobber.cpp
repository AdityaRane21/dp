// recursion // tle
class Solution {
public:
    int solve(vector<int>&nums,int i){
        if(i>=nums.size()) return 0;

        int steal=nums[i]+solve(nums,i+2);
        int skip=solve(nums,i+1);

        return max(steal,skip);
    }
    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
};

// memoization 
class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int steal = nums[i] + solve(nums, i + 2, dp);
        int skip  = solve(nums, i + 1, dp);

        return dp[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};

// memoization 
// memoization
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int& n) {
        if(i >= n) return 0;
        
        if(t[i] != -1) return t[i]; // already calculated 
        
        int take = nums[i] + solve(nums, i+2, n); //steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, i+1, n); //skips this house, now we can move to adjacent next house
        
        return t[i]=max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};

// bottom up

