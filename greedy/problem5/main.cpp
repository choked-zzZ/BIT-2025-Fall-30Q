#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main(int argc, char *argv[]) {
    vector<pii> pos;
    vector<pii> neg;
    int n = 0;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (b > 0) {
            pos.push_back(make_pair(a, b));
        } else {
            neg.push_back(make_pair(a, b));
        }
    }
    sort(pos.begin(), pos.end(), [](pii p1, pii p2) { return p1.first < p2.first; });
    sort(neg.begin(), neg.end(),
         [](pii p1, pii p2) { return p1.first + p1.second > p2.first + p2.second; });
    ll a = 0, acc = 0;
    for (auto x : pos) {
        if (x.first > a) {
            acc += x.first - a;
            a = x.first;
        }
        a += x.second;
    }
    for (auto x : neg) {
        if (x.first > a) {
            acc += x.first - a;
            a = x.first;
        }
        a += x.second;
    }
    cout << acc << endl;
    return 0;
}
