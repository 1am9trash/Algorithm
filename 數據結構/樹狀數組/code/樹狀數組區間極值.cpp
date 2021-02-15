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

// 樹狀數組（單點修改、區間最值）
// 1-base

// luogu P1531

#define MAXN 200001
#define lowBit(x) ((x) & (-x))

int tree[MAXN], a[MAXN];

void update(int cur, int value, int capacity) {
    a[cur] = value;
    while (cur <= capacity) {
        tree[cur] = a[cur];
        for (int i = 1; i < lowBit(cur); i <<= 1)
            tree[cur] = max(tree[cur], tree[cur - i]);
        cur += lowBit(cur);
    }
}

int query(int l, int r) {
    int ret = a[r];
    while (r >= l) {
        ret = max(ret, a[r]);
        for (--r; r - lowBit(r) >= l; r -= lowBit(r))
            ret = max(ret, tree[r]);
    }
    return ret;
}

signed main() {
    io();

    int n, m;
    cin >> n >> m;

    int value;
    for (int i = 1; i <= n; i++) {
        cin >> value;
        update(i, value, n);
    }

    int x, y;
    char op;
    for (int i = 0; i < m; i++) {
        cin >> op >> x >> y;
        if (op == 'U') {
            if (a[x] < y)
                update(x, y, n);
        } else
            cout << query(x, y) << "\n";
    }

    return 0;
}