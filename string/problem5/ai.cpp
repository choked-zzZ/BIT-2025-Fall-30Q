#include <bits/stdc++.h>
using namespace std;

const string target = "fattyhappy";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        bool ok = false;
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        if (n >= 10) {
            for (int L = 0; L + 10 <= n && !ok; ++L) {
                vector<int> diff;
                for (int j = 0; j < 10; j++) {
                    if (s[L + j] != target[j])
                        diff.push_back(j);
                }
                if (diff.size() == 2) {
                    int a = diff[0], b = diff[1];
                    if (s[L + a] == target[b] && s[L + b] == target[a]) {
                        cout << L + a + 1 << " " << L + b + 1 << "\n";
                        ok = true;
                    }
                } else if (diff.size() == 1) {
                    int k = diff[0];
                    char need = target[k];
                    int idx = need - 'a';
                    for (int p : pos[idx]) {
                        if (p < L || p >= L + 10) {
                            cout << L + k + 1 << " " << p + 1 << "\n";
                            ok = true;
                            break;
                        }
                    }
                } else if (diff.empty()) {
                    cout << L + 3 << " " << L + 4 << "\n";
                    ok = true;
                }
            }
        }
        if (!ok)
            cout << -1 << "\n";
    }
    return 0;
}
