#include <algorithm>
#include <iomanip>
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

// 三分

// luogu P3382

const double eps = 1e-7;

int n;
double a[14];

double f(double x) {
    double ret = 0, cur = 1;
    for (int i = 0; i <= n; i++) {
        ret += cur * a[i];
        cur *= x;
    }
    return ret;
}

double ternary(double l, double r) {
    while (r - l > eps) {
        // cout << l << " " << r << "\n";
        double tl = l + (r - l) / 3, tr = r - (r - l) / 3;
        if (f(tl) > f(tr))
            r = tr;
        else
            l = tl;
    }
    return l;
}

signed main() {
    io();

    double l, r;
    cin >> n >> l >> r;
    for (int i = n; i >= 0; i--)
        cin >> a[i];
    cout << setprecision(10) << ternary(l, r);

    return 0;
}