#include "bits/stdc++.h"
#include <cstdio>
#include <cstring>
using namespace std;

inline int mapci(char c) {
    switch (c) {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    case 'P':
    case 'R':
    case 'S':
        return 7;
    case 'T':
    case 'U':
    case 'V':
        return 8;
    case 'W':
    case 'X':
    case 'Y':
        return 9;
    case 'Q':
    case 'Z':
        return -1;
    default:
        return -1;
    }
}

int main(int argc, char *argv[]) {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    char tmp[21], s[8];
    bool errf = false;
    int errcnt = 0;
    int dupcnt = 0;
    static bitset<2000005> bmp;
    struct phone {
        int num;
        int repeat;
    } dup[1501];
    // cout << "Error:" << endl;
    printf("Error:\n");
    while (scanf("%s", tmp) != EOF) {
        int l = 0;
        for (int i = 0; i < strlen(tmp); ++i) {
            char chr = tmp[i];
            if (chr == '-') {
                continue;
            } else if ('A' <= chr && chr <= 'Z') {
                int i = mapci(chr);
                if (i == -1) {
                    errf = true;
                } else {
                    s[l++] = i + '0';
                }
            } else {
                s[l++] = chr;
            }
        }
        s[l] = '\0';
        if (s[0] != '3' && s[0] != '6') {
            errf = true;
        }
        if (errf) {
            // cout << tmp << endl;
            printf("%s\n", tmp);
            errcnt += 1;
            errf = false;
            continue;
        }
        int act_num = atoi(s);
        int val = act_num - (s[0] == '3' ? 3 : 5) * 1000000;
        if (bmp[val]) {
            bool find = false;
            for (int i = 0; i < dupcnt; ++i) {
                if (act_num == dup[i].num) {
                    dup[i].repeat += 1;
                    find = true;
                    break;
                }
            }
            if (!find) {
                dup[dupcnt].num = act_num;
                dup[dupcnt].repeat = 2;
                dupcnt += 1;
            }
        } else {
            bmp.set(val);
        }
        errf = false;
    }
    if (errcnt == 0) {
        // cout << "Not found." << endl;
        printf("Not found.\n");
    }
    printf("\n");
    // cout << endl;
    // cout << "Duplication:" << endl;
    printf("Duplication:\n");
    if (dupcnt == 0) {
        //     cout << "Not found." << endl;
        printf("Not found.\n");
    } else {
        sort(dup, dup + dupcnt, [&](phone a, phone b) { return a.num < b.num; });
        for (int i = 0; i < dupcnt; ++i) {
            int three = dup[i].num / 10000;
            int four = dup[i].num % 10000;
            printf("%d-%04d", three, four);
            printf(" %d\n", dup[i].repeat);
        }
    }
    return 0;
}
