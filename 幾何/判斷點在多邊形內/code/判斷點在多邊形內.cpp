#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#pragma GCC optimize("O2")

#define _9trash no WA
#define ll long long
#define ld long double
#define pb push_back

void io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// -------------------------------------------------------------

// 射線法

// HDU 1756

struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point operator+(const point &a) const {
        return point(x + a.x, y + a.y);
    }
    point operator-(const point &a) const {
        return point(x - a.x, y - a.y);
    }
    double operator*(const point &a) const {
        return x * a.x + y * a.y;
    }
    double operator^(const point &a) const {
        return x * a.y - a.x * y;
    }
};

double eps = 1e-8;

int dcmp(double x) {
    if (x < -eps)
        return -1;
    return x > eps;
}

bool pointOnLine(point a, point b, point p) {
    return dcmp((a - p) ^ (b - p)) == 0 && dcmp((a - p) * (b - p)) <= 0;
}

bool chk(point p, vector<point> &points) {
    int ans = 0, k, d1, d2;
    for (int i = 0; i < points.size(); i++) {
        point a = points[i], b = points[(i + 1) % points.size()];

        if (pointOnLine(a, b, p))
            return true;
        k = dcmp((b - a) ^ (p - a));
        d1 = dcmp(a.y - p.y);
        d2 = dcmp(b.y - p.y);
        cout << k << " " << d1 << " " << d2 << "\n";
        if (k > 0 && d1 <= 0 && d2 > 0)
            ans++;
        else if (k < 0 && d2 <= 0 && d1 > 0)
            ans++;
    }
    return ans % 2;
}

signed main() {
    io();

    int n, m;
    while (cin >> n) {
        vector<point> v;
        point checkPoint;

        double x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v.pb(point(x, y));
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> checkPoint.x >> checkPoint.y;
            if (chk(checkPoint, v))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}