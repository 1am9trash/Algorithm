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

// 模逆元

// luogu P1082

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

ll invMod(ll i, ll p) {
    i = abs(i);
    p = abs(p);

    ll x, y, ret;
    ret = exgcd(i % p, p, x, y);
    return (ret == 1) ? ((x % p) + p) % p : -1;
}

signed main() {
    io();

    ll a, b;
    cin >> a >> b;
    cout << invMod(a, b);

    return 0;
}