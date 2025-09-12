#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

// int read() {
//     int ret = 0, c;
//     for (; !isdigit(c); c = getchar())
//         ;
//     for (; isdigit(c); c = getchar())
//         ret = (ret << 3) + (ret << 1) + (c ^ 48);
//     return ret;
// }

char mp[1005][1005];
bool vis[1005][1005];
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
        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j <= k; ++j) {
                int x = xy.first + dx[i] * j, y = xy.second + dy[i] * j;
                if (x < 1 || x > n || y < 1 || y > m || mp[x][y] == '#')
                    break;
                pii tar = make_pair(x, y);
                if (!vis[x][y]) {
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
