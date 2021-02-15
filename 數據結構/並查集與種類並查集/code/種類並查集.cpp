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

// 種類並查集（兩種）
// 1-base

// luogu P1525

#define MAXN 20000

int anc[2 * MAXN + 1];

void init(int n) {
    for (int i = 1; i <= 2 * n; i++)
        anc[i] = i;
}

int findAnc(int cur) {
    return cur == anc[cur] ? cur : anc[cur] = findAnc(anc[cur]);
}

void merge(int a, int b) {
    anc[findAnc(a)] = findAnc(b);
}

struct fight {
    int a, b, c;

    fight() {}
    fight(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator<(const fight &t) const {
        return c > t.c;
    }
};

vector<fight> v;

signed main() {
    io();

    int n, m;
    cin >> n >> m;

    init(n);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v.pb(fight(a, b, c));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        if (findAnc(v[i].a) == findAnc(v[i].b)) {
            cout << v[i].c;
            return 0;
        }
        merge(v[i].a, v[i].b + n);
        merge(v[i].b, v[i].a + n);
    }
    cout << 0;

    return 0;
}