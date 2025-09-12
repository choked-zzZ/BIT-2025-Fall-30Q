#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(y.begin(), y.end());
    sort(x.begin(), x.end());
    ll ym = y[n >> 1];
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(y[i] - ym);
        x[i] -= i;
    }
    sort(x.begin(), x.end());
    ll xm = x[n >> 1];
    for (int i = 0; i < n; ++i) {
        ans += abs(x[i] - xm);
    }

    cout << ans << endl;

    return 0;
}
