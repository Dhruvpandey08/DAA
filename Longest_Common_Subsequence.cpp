#include <iostream>
#include <string>
using namespace std;

class LCS {
public:
    int longest(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    LCS lcs;
    string str1, str2;
    cin >> str1 >> str2;
    int ans = lcs.longest(str1, str2);
    cout << ans << endl;
    return 0;
}