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

// 樹狀數組（單點修改、區間和）
// 1-base

// luogu P3374

#define MAXN 500001
#define lowBit(x) ((x) & (-x))

int tree[MAXN], a[MAXN];

void update(int cur, int addValue, int capacity) {
    a[cur] += addValue;
    while (cur <= capacity) {
        tree[cur] += addValue;
        cur += lowBit(cur);
    }
}

int query(int cur) {
    int ret = 0;
    while (cur > 0) {
        ret += tree[cur];
        cur -= lowBit(cur);
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

    int op, x, y;
    for (int i = 0; i < m; i++) {
        cin >> op >> x >> y;
        if (op == 1)
            update(x, y, n);
        else
            cout << query(y) - query(x - 1) << "\n";
    }

    return 0;
}