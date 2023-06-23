#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
int p[MAXN], dp[MAXN][MAXN], nxt[MAXN][MAXN];

void printMatrixChain(int i, int j) 
{
    if (i == j) 
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printMatrixChain(i, nxt[i][j]);
    cout << " x ";
    printMatrixChain(nxt[i][j] + 1, j);
    cout << ")";
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) 
    {
        cin >> p[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) 
    {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) 
    {
        for (int i = 1; i + len -1 <= n; i++) 
        {
            int j = i + len -1;
            for (int k = i; k < j; k++)
            {
                int q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < dp[i][j]) 
                {
                    dp[i][j] = q;
                    nxt[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of multiplications: " << dp[1][n] << endl;
    cout << "Parenthesized matrix chain: ";
    printMatrixChain(1, n);
    cout << endl;
    return 0;
}