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

// -------------------------------------------------------------

// st表（區間最值）
// 1-base

// luogu P3865

#define MAXN 100001

int lg2[MAXN], st[MAXN][21], a[MAXN];

void pre(int n) {
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i / 2] + 1;
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    for (int i = 1; i < 21; i++)
        for (int j = 1; j <= n; j++) {
            if (j + (1 << i) - 1 > n)
                break;
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
}

int query(int l, int r) {
    return max(st[l][lg2[r - l + 1]], st[r - (1 << lg2[r - l + 1]) + 1][lg2[r - l + 1]]);
}

signed main() {
    io();

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    pre(n);

    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }

    return 0;
}