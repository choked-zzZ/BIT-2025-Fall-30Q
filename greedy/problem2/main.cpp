#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(int argc, char *argv[]) {
    int n = 0;
    cin >> n;
    vector<pii> arr;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end(), [](pii p1, pii p2) { return p1.second < p2.second; });
    int ans = 0, till = -1;
    for (pii p : arr) {
        if (p.first >= till) {
            till = p.second;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
