#include <bits/stdc++.h>
#include <cstring>
using namespace std;

constexpr int MX = 105;

int f1[MX], f2[MX], dp[MX][MX], cnt = 0;

int read() {
    int ret = 0, c;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    return ret;
}

int solve() {
    int n = read(), m = read();
    if (!n && !m) {
        return 1;
    }
    for (int i = 0; i < n; ++i)
        f1[i] = read();
    for (int i = 0; i < m; ++i)
        f2[i] = read();
    memset(dp, 0, sizeof dp);
    dp[0][0] = (int)f1[0] == f2[0];
    // 初始化边界
    for (int i = 1; i < n; ++i)
        dp[i][0] = (int)f1[i] == f2[0];
    // 初始化边界
    for (int j = 1; j < m; ++j)
        dp[0][j] = (int)f1[0] == f2[j];
    // 状态转移
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            dp[i][j] = f1[i] == f2[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    cout << "Twin Towers #" << ++cnt << endl;
    cout << "Number of Tiles : " << dp[n - 1][m - 1] << endl;
    return 0;
}

int main(int argc, char *argv[]) {
    // 自己看solve的返回值理解
    while (!solve())
        ;
    return 0;
}
