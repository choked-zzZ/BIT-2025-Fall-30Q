#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

char mp[1005][1005];
bool vis[1005][1005];
// 四个方向
constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(vis, 0, sizeof vis);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
        }
    }
    queue<pair<pii, int>> q;
    int t1, t2, t3, t4;
    cin >> t1 >> t2 >> t3 >> t4;
    pii st = make_pair(t1, t2);
    pii en = make_pair(t3, t4);
    q.emplace(st, 0);
    vis[st.first][st.second] = true;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        pii xy = p.first;
        int step = p.second;
        // 向四个方向前进
        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j <= k; ++j) {
                // 新坐标
                int x = xy.first + dx[i] * j, y = xy.second + dy[i] * j;
                // 越界或者障碍物
                if (x < 1 || x > n || y < 1 || y > m || mp[x][y] == '#')
                    break;
                pii tar = make_pair(x, y);
                // 没访问过
                if (!vis[x][y]) {
                    // 到达终点 之前那样写也可以 但是肯定会慢一点
                    if (tar == en) {
                        cout << step + 1 << endl;
                        return 0;
                    }
                    vis[x][y] = true;
                    q.emplace(tar, step + 1);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
