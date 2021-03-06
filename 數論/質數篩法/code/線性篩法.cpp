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

// 線性篩法

// luogu P3383

#define MAXN 100000001

vector<int> p;
vector<bool> mark(MAXN, 0);

void isPrime(int n) {
    mark[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!mark[i])
            p.pb(i);
        for (int j = 0; i * p[j] <= n; j++) {
            mark[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}

signed main() {
    io();

    int n, q;
    cin >> n >> q;

    isPrime(n);

    int k;
    for (int i = 0; i < q; i++) {
        cin >> k;
        cout << p[k - 1] << "\n";
    }

    return 0;
}