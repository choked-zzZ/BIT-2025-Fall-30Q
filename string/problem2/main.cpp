#include "bits/stdc++.h"
using namespace std;

int n;

int main(int argc, char *argv[]) {
    cin >> n;
    unordered_set<string> mp;
    string s;
    while (n--) {
        cin >> s;
        if (s.length() > 10) {
            mp.insert(s);
        }
    }
    cout << mp.size() << endl;
    return 0;
}
