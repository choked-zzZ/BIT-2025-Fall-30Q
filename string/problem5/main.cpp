#include "bits/stdc++.h"
using namespace std;

int t;
string s;
string target = "fattyhappy";
int char_index[26];

int main(int argc, char *argv[]) {
    cin >> t;
    while (t--) {
        cin >> s;
        int i = 0;
        bool find = false;
        while (i < s.length()) {
            if (s[i] != 'f') {
                ++i;
                char_index[s[i] - 'a'] = i;
                continue;
            }
            int j = 0, errcnt = 0, err[2];
            while (j < 10) {
                if (target[j] != s[i + j]) {
                    err[errcnt] = j;
                    if (++errcnt > 2) {
                        break;
                    }
                    repl = char_index[target[j]];
                    orig = j;
                    if (repl == -1) {
                        break;
                    }
                }
                if (errcnt > 2) {
                    break;
                }
                j++;
            }
            if (errcnt == 0) {
                cout << i + 3 << " " << i + 4 << endl;
            } else {
                find = true;
                cout << orig << " " << repl << endl;
            }
            ++i;
        }
        if (!find)
            cout << -1 << endl;
    }
    return 0;
}
