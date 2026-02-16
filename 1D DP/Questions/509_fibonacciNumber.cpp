// basic recursion // 2^n
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// memoization
class Solution {
public:
    int solve(int n,vector<int>&dp){

        if(n<=1) return n;
        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int fib(int n) {
        if(n<=1) return n;

        vector<int>dp(n+1,-1);

        return solve(n,dp);
    }

};

// bottom up
class Solution {
public:
    int fib(int n) {
        
        if(n <= 1)
            return n;
        
        int t[n+1];
        //State definition
        //t[i] = ith Fibonacci Number
        
        t[0] = 0;
        t[1] = 1;
        
        for(int i = 2; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        
        return t[n];
        
    }
};

// constant space 
class Solution {
public:
    int fib(int n) {
        if( n<=1) return n;
        
        int c;
        int a = 0, b = 1;
        
        for(int i = 1; i<n; i++) {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
    
};
