// recursion // tle
// skip karenge toh sign same rahega
// take karenge toh sign badlega
class Solution {
public:
    typedef long long ll;
    int n;

    ll solve(int idx,vector<int>&nums,bool flag){
        if(idx>=n) return 0;

        ll skip=solve(idx+1,nums,flag); // sign of flag remains as it is

        ll val=nums[idx];
        if(flag==false) val=-val;

        ll take=solve(idx+1,nums,!flag) + val;

        return max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();

        return solve(0,nums,true); // 0th index is even // true : +
    }
};

// memoization
class Solution {
public:
    typedef long long ll;
    int n;
    long long t[1000001][2]; // index, flag

    ll solve(int idx,vector<int>&nums,bool flag){
        if(idx>=n) return 0;

        if(t[idx][flag] != -1) return t[idx][flag];

        ll skip=solve(idx+1,nums,flag); // sign of flag remains as it is

        ll val=nums[idx];
        if(flag==false) val=-val;

        ll take=solve(idx+1,nums,!flag) + val;

        return t[idx][flag]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,true); // 0th index is even // true : +
    }
};

// bottom up
