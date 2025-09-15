#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// 树状数组
constexpr int MX = 300005;
int n, tree[MX], n_max_val;

inline int lowbit(int x) {
    return x & (-x);
}

ull query(int x) {
    ull ans = 0;
    for (; x > 0; x -= lowbit(x))
        ans += tree[x];
    return ans;
}

void update(int x) {
    for (; x <= n_max_val; x += lowbit(x))
        tree[x] += 1;
}

int main(int argc, char *argv[]) {
    cin >> n;
    ull ans = 0;
    vector<int> orig(n);
    vector<int> disc(n);
    for (int i = 0; i < n; ++i) {
        cin >> orig[i];
        disc[i] = orig[i];
    }
    sort(disc.begin(), disc.end());
    disc.erase(unique(disc.begin(), disc.end()), disc.end());
    n_max_val = disc.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n_max_val; ++i) {
        mp.emplace(disc[i], i + 1);
    }
    for (int i = 0; i <= n_max_val; ++i) {
        tree[i] = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        ans += query(mp[orig[i]] - 1);
        update(mp[orig[i]]);
    }
    cout << ans << endl;

    return 0;
}
