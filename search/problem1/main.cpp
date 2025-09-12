#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int read() {
    int ret = 0, c;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    return ret;
}

int main(int argc, char *argv[]) {
    int m = read();
    vector<vector<int>> g(1000000);
    for (int i = 0; i < m; ++i) {
        int st = read();
        read(), read();
        int en = read();
        g[st].push_back(en);
    }
    int sa = read(), sb = read(), sc = read(), gst = read();
    int gen = read(), eb = read(), ec = read(), ed = read();
    if (sa == gen && sb == eb && sc == ec && gst == ed) {
        cout << 1 << endl;
        return 0;
    }
    queue<pii> q;
    unordered_set<int> vis;
    q.push(make_pair(gst, 0));
    while (!q.empty()) {
        auto p = q.front();
        if (p.first == gen) {
            cout << p.second + 2 << endl;
            return 0;
        }
        q.pop();
        for (int nxt : g[p.first]) {
            if (vis.find(nxt) == vis.end()) {
                q.push(make_pair(nxt, p.second + 1));
                vis.insert(nxt);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
