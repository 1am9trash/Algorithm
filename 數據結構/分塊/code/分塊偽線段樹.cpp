#include <algorithm>
#include <cmath>
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

// 分塊（區間修改、區間和）
// 1-base

// luogu P3372

#define MAXN 100001
#define SQRTN 500

ll a[MAXN], be[MAXN], st[SQRTN], en[SQRTN], sum[SQRTN], lazy[SQRTN];

void pre(int n) {
    int sq = sqrt(n), cnt = (n + sq - 1) / sq;
    for (int i = 1; i <= cnt; i++) {
        st[i] = (i - 1) * sq + 1;
        en[i] = i * sq;
    }
    en[cnt] = n;
    for (int i = 1; i <= cnt; i++)
        for (int j = st[i]; j <= en[i]; j++) {
            sum[i] += a[j];
            be[j] = i;
        }
}

void update(int x, int y, ll k) {
    if (be[x] == be[y]) {
        for (int i = x; i <= y; i++) {
            a[i] += k;
            sum[be[i]] += k;
        }
        return;
    }
    for (int i = x; i <= en[be[x]]; i++) {
        a[i] += k;
        sum[be[i]] += k;
    }
    for (int i = st[be[y]]; i <= y; i++) {
        a[i] += k;
        sum[be[i]] += k;
    }
    for (int i = be[x] + 1; i <= be[y] - 1; i++)
        lazy[i] += k;
}

ll query(int x, int y) {
    ll ret = 0;
    if (be[x] == be[y]) {
        for (int i = x; i <= y; i++)
            ret += a[i] + lazy[be[i]];
        return ret;
    }
    for (int i = x; i <= en[be[x]]; i++)
        ret += a[i] + lazy[be[i]];
    for (int i = st[be[y]]; i <= y; i++)
        ret += a[i] + lazy[be[i]];
    for (int i = be[x] + 1; i <= be[y] - 1; i++)
        ret += sum[i] + (en[i] - st[i] + 1) * lazy[i];
    return ret;
}

signed main() {
    io();

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pre(n);

    ll op, x, y, k;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update(x, y, k);
        } else {
            cin >> x >> y;
            cout << query(x, y) << "\n";
        }
    }

    return 0;
}