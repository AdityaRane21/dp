// recursion will give tle
class Solution {
public:
    int solve(int n){
        if(n<0){
            return 0;
        }
        if(n==0) return 1;

        int one_step = solve(n-1);
        int two_steps = solve(n-2);

        return one_step+two_steps;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};

// memoization
class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<0){
            return 0;
        }
        if(n==0) return 1;

        if(dp[n]!=-1) return dp[n]; // dp[n]!=-1 means already solved

        int a = solve(n-1,dp);
        int b = solve(n-2,dp);
        
        return dp[n] = a+b;

    }
    int climbStairs(int n) {

        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

// memoisation // array declared outside only // no need to pass in function
class Solution {
public:
    int dp[46]; // contraints upto 45
    int solve(int n){
        if(n<0){
            return 0;
        }
        if(n==0) return 1;

        if(dp[n]!=-1) return dp[n]; // dp[n]!=-1 means already solved

        int a = solve(n-1);
        int b = solve(n-2);
        
        return dp[n] = a+b;

    }
    int climbStairs(int n) {

        memset(dp,-1,sizeof(dp)); // initialize with -1
        return solve(n);
    }
};

// bottom up
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        
        vector<int> t(n+1);
        
        //t[i] = total ways to climb i stairs
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;
        
        for(int i = 3; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        
        return t[n];
    }
};

// 
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int a = 1, b = 2, c;
        for (int i = 3; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
