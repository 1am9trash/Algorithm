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

// 並查集
// 1-base

// luogu P3367

#define MAXN 200001

int anc[MAXN];

void init(int n) {
    for (int i = 1; i <= n; i++)
        anc[i] = i;
}

int findAnc(int cur) {
    return cur == anc[cur] ? cur : anc[cur] = findAnc(anc[cur]);
}

void merge(int a, int b) {
    anc[findAnc(a)] = findAnc(b);
}

signed main() {
    io();

    int n, m;
    cin >> n >> m;

    init(n);

    int z, x, y;
    for (int i = 0; i < m; i++) {
        cin >> z >> x >> y;
        if (z == 1)
            merge(x, y);
        else {
            if (findAnc(x) == findAnc(y))
                cout << "Y\n";
            else
                cout << "N\n";
        }
    }

    return 0;
}