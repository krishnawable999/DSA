#include<iostream>
#include<vector>
using namespace std;


int solveUsingRE(int n , int k){

    if(n == 1) return k;
    if(n == 2) return (k + k*(k-1));

    int ans = (solveUsingRE(n-1,k) + solveUsingRE(n-2,k))*(k-1);

    return ans;

}

int solveUsingMem(int n , int k, vector<int> &dp){
    if(n == 1) return k;
    if(n == 2) return (k + k*(k-1));
    // check if ans is existing
    if(dp[n] != -1){
        return dp[n];
    }

    // store the ans in dp array
    dp[n] = (solveUsingMem(n-1,k,dp) + solveUsingMem(n-2,k, dp))*(k-1);

    return dp[n];
}

int solveUsingTabulation(int n, int k , vector<int> &dp){
    dp[1] = k;
    dp[2]= k + k*(k-1);

    for(int i=3 ; i<=n ; i++){
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }

    return dp[n];
}

int main(){
    // int ans = solveUsingRE(3,2);
    // cout<<ans;
    int n = 3;
    int k = 3;
    vector<int> dp(n+1,-1);
    // int ans = solveUsingMem(n,k,dp);
    // cout<<ans;
    int ans = solveUsingTabulation(n,k,dp);
    cout<<ans;

}