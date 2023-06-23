#include <iostream>
#include <vector>
using namespace std;

int num_ways(int n) 
{
    vector<vector<int>> dp(n,vector<int>(n));
    for (int i = 0; i < n; i++) 
    {
        dp[i][i] = 1;
        for (int len = 2; len <= n; len++) 
        {
            for (int i = 0; i <= n-len; i++) 
            {
                int j = i + len-1;
                dp[i][j] = 0;
                for (int k = i; k < j; k++) 
                {
                    dp[i][j] += dp[i][k] * dp[k+1][j];
                }
            }
        } 
    }
     return dp[0][n-1];
}
int main() 
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    cout << "Number of ways to parenthesize " << n << " matrices: " <<
    num_ways(n) << endl;
    return 0;
}