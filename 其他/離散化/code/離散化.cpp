#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#pragma GCC optimize("O2")

#define _9trash no WA
#define ll long long
#define pb push_back

void io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// ------------------------------------------------------------

// 離散化
// 1-base

// luogu P1955

#define MAXN 1000001

vector<int> v;
int n;

void discrete() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int anc[MAXN], a[MAXN][3];

int findAnc(int cur) {
    return cur == anc[cur] ? cur : anc[cur] = findAnc(anc[cur]);
}

signed main() {
    io();

    int t;
    cin >> t;
    bool ok;
    while (t--) {
        v.clear();
        ok = 1;

        cin >> n;
        for (int i = 0; i < n; i++) {
            anc[2 * i + 1] = 2 * i + 1;
            anc[2 * i + 2] = 2 * i + 2;
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            v.pb(a[i][0]);
            v.pb(a[i][1]);
        }
        discrete();
        for (int i = 0; i < n; i++) {
            a[i][0] = lower_bound(v.begin(), v.end(), a[i][0]) - v.begin() + 1;
            a[i][1] = lower_bound(v.begin(), v.end(), a[i][1]) - v.begin() + 1;
            if (a[i][2] == 1)
                anc[findAnc(a[i][0])] = findAnc(a[i][1]);
        }
        for (int i = 0; i < n; i++)
            if (a[i][2] == 0)
                if (findAnc(a[i][0]) == findAnc(a[i][1])) {
                    cout << "NO\n";
                    ok = 0;
                    break;
                }
        if (ok)
            cout << "YES\n";
    }

    return 0;
}