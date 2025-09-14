#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 8个坐标 你可以弄成9个 把(0, 0)放在里面
const int di[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dj[8] = {2, 1, -1, -2, -2, -1, 1, 2};

// 注意数据范围
ll dp[25][25];

int main(int argc, char *argv[]) {
    memset(dp, 0, sizeof dp);
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    // 当时采用的-1作为不能通过的标记 不过会有更简单的方法 大家自行摸索吧
    for (int i = 0; i < 8; ++i) {
        int x = c1 + di[i], y = c2 + dj[i];
        if (x < 0 || y < 0 || x > n || y > m)
            continue;
        dp[x][y] = -1ll;
    }
    dp[c1][c2] = -1;

    // 如果边界出现在了第一行或者第一列 之后的都不可达 直接break
    // 这一段是初始化边界
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

    // 开始状态转移
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 是障碍
            if (dp[i][j] == -1)
                continue;
            // 两边都是障碍
            if (dp[i - 1][j] == -1 && dp[i][j - 1] == -1) {
                dp[i][j] = 0ll;
                // 左边是障碍
            } else if (dp[i - 1][j] == -1) {
                dp[i][j] = dp[i][j - 1];
                // 上边是障碍
            } else if (dp[i][j - 1] == -1) {
                dp[i][j] = dp[i - 1][j];
                // 都不是障碍
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
