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

// 擴展歐幾里德

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    ll ret = exgcd(b % a, a, x, y);
    ll temp = x;
    x = -(b / a) * x + y;
    y = temp;

    return ret;
}

signed main() {
    io();

    ll a, b, x, y, ret;
    cin >> a >> b;

    a = abs(a);
    b = abs(b);
    if (a > b)
        swap(a, b);

    ret = exgcd(a, b, x, y);
    cout << a << " * " << x
         << " + "
         << b << " * " << y
         << " = " << ret << "\n";

    return 0;
}