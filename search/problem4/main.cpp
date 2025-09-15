#include <bits/stdc++.h>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

constexpr static pii DIRS[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int n, m;
char c;

constexpr int MX = 2005;
char mp[MX][MX];
bool vis[MX][MX];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    pii st, en;
    // 传送点集合
    vector<pii> tp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mp[i][j];
            char c = mp[i][j];
            if (c == 'N') {
                st = make_pair(i, j);
            } else if (c == 'C') {
                en = make_pair(i, j);
            } else if (c == 'E') {
                tp.emplace_back(i, j);
            }
        }
    }
    queue<pair<pii, int>> q;
    bool tp_used = false;
    q.emplace(st, 0);
    vis[st.first][st.second] = true;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        pii xy = p.first;
        int step = p.second;
        // 到达终点
        if (xy == en) {
            cout << step << endl;
            return 0;
        }
        for (pii dir : DIRS) {
            int x = xy.first + dir.first, y = xy.second + dir.second;
            if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == 'M')
                continue;
            pii tar = make_pair(x, y);
            if (!vis[x][y]) {
                // 传送点且传送点没用过
                if (mp[x][y] == 'E' && !tp_used) {
                    tp_used = true;
                    for (auto tpxy : tp) {
                        vis[tpxy.first][tpxy.second] = true;
                        q.emplace(tpxy, step + 1);
                    }
                    // 不是传送点
                } else {
                    vis[x][y] = true;
                    q.emplace(tar, step + 1);
                }
            }
        }
    }
    cout << "Bad Eureka" << endl;
    return 0;
}
