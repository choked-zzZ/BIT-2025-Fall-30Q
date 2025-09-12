#include <bits/stdc++.h>
using namespace std;
using ull = __uint64_t;

int t;
ull n;

int main(int argc, char *argv[]) {
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (n != 1 ? 64 - __builtin_clzll(n - 1) : 0) << endl;
    }
    return 0;
}
