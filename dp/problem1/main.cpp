#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int di[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dj[8] = {2, 1, -1, -2, -2, -1, 1, 2};

ll dp[25][25];

int main(int argc, char *argv[]) {
    memset(dp, 0, sizeof dp);
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < 8; ++i) {
        int x = c1 + di[i], y = c2 + dj[i];
        if (x < 0 || y < 0 || x > n || y > m)
            continue;
        dp[x][y] = -1ll;
    }
    dp[c1][c2] = -1;
    for (int i = 0; i <= n; ++i) {
        if (dp[i][0] == -1)
            break;
        dp[i][0] = 1ll;
    }
    for (int i = 0; i <= m; ++i) {
        if (dp[0][i] == -1)
            break;
        dp[0][i] = 1ll;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] == -1)
                continue;
            if (dp[i - 1][j] == -1 && dp[i][j - 1] == -1) {
                dp[i][j] = 0ll;
            } else if (dp[i - 1][j] == -1) {
                dp[i][j] = dp[i][j - 1];
            } else if (dp[i][j - 1] == -1) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
