#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 10000000;
constexpr int MX = 2005;

int read() {
    int ret = 0, c;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    return ret;
}

int dp[2][MX], n, v;

int main(int argc, char *argv[]) {
    memset(dp, 0, sizeof dp);
    n = read(), v = read();
    dp[0][0] = 1;
    int f;
    for (int i = 0; i < n; ++i) {
        f = i & 1;
        int vo = read();
        for (int j = 0; j < v; ++j)
            dp[f ^ 1][j] = 0;
        for (int j = 0; j < v; ++j) {
            dp[f ^ 1][j] += dp[f][j];
            dp[f ^ 1][(j + vo) % v] += dp[f][j];
            dp[f ^ 1][j] %= MOD;
            dp[f ^ 1][(j + vo) % v] %= MOD;
        }
        // cout << "#" << i << ":" << endl;
        // for (int i = 0; i < 2; ++i) {
        //     for (int j = 0; j < v; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    cout << (dp[f ^ 1][0] - 1 + MOD) % MOD << endl;
    return 0;
}
