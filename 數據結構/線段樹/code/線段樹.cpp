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

// 線段樹（區間和）
// 1-base

// luogu P3372

#define lId (id << 1)
#define rId (id << 1 | 1)
#define MAXN 100001

ll a[MAXN];

struct segmentTree {
    int l, r;
    ll lazy;
    ll sum;
    inline int len() {
        return r - l + 1;
    }
} tree[MAXN * 4];

void pushUp(int id) {
    tree[id].sum = tree[lId].sum + tree[rId].sum;
}

void pushDown(int id) {
    if (!tree[id].lazy)
        return;
    tree[lId].lazy += tree[id].lazy;
    tree[rId].lazy += tree[id].lazy;

    tree[lId].sum += tree[id].lazy * tree[lId].len();
    tree[rId].sum += tree[id].lazy * tree[rId].len();

    tree[id].lazy = 0;
}

void build(int id, int bl, int br) {
    tree[id].l = bl;
    tree[id].r = br;
    tree[id].lazy = 0;

    if (bl == br) {
        tree[id].sum = a[bl];
        return;
    }

    int mid = (bl + br) >> 1;
    build(lId, bl, mid);
    build(rId, mid + 1, br);
    pushUp(id);
}

void updateInterval(int id, int ul, int ur, ll value) {
    int l, r;
    l = tree[id].l;
    r = tree[id].r;

    if (ul <= l && r <= ur) {
        tree[id].sum += value * tree[id].len();
        tree[id].lazy += value;
        return;
    }

    pushDown(id);
    int mid = (l + r) >> 1;
    if (ul <= mid)
        updateInterval(lId, ul, ur, value);
    if (ur > mid)
        updateInterval(rId, ul, ur, value);
    pushUp(id);
}

ll query(int id, int ql, int qr) {
    int l, r;
    l = tree[id].l;
    r = tree[id].r;

    if (ql <= l && r <= qr)
        return tree[id].sum;

    pushDown(id);
    ll ret = 0;
    int mid = (l + r) >> 1;
    if (ql <= mid)
        ret += query(lId, ql, qr);
    if (qr > mid)
        ret += query(rId, ql, qr);

    return ret;
}

int main() {
    io();

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    int op, x, y, k;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            updateInterval(1, x, y, k);
        } else {
            cin >> x >> y;
            cout << query(1, x, y) << "\n";
        }
    }

    return 0;
}