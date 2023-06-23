#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int dp[MAXN][MAXN];
int n;
int a[MAXN];
int solve(int i, int j) 
{
    if (i == j) 
    {
        return 0;
    }
    // Check if we have already solved this subproblem
    if (dp[i][j] != -1) 
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++) 
    {
    // Cost to multiply matrices (i, k) and (k+1, j)
    int cost = solve(i, k) + solve(k+1, j) + a[i-1]*a[k]*a[j];
    // Update answer if cost is lower
    ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int main() 
{
    cin >> n;
    // Input dimensions of matrices
    for (int i = 0; i <= n; i++) 
    {
        cin >> a[i];
    }
    
    // Initialize dp table with -1
    memset(dp, -1, sizeof(dp));
    // Call solve function on the entire range
    cout << "Minimum cost: " << solve(1, n) << endl;
    // Print the dp table
    cout << "DP table:" << endl;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}