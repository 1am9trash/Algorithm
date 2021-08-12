#include <algorithm>
#include <cmath>
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

#pragma GCC optimize("O3")

#define _9trash no WA
#define ll long long
#define pb push_back

void io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// -------------------------------------------------------------

// 兩圓交點

double eps = 1e-6;

struct NODE {
    double x, y;
    NODE() {}
    NODE(double x, double y) : x(x), y(y) {}
};

double disSq(NODE a, NODE b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double radT(NODE c1, NODE c2) {
    NODE c1c2 = NODE(c2.x - c1.x, c2.y - c1.y);
    return atan2(c1c2.y, c1c2.x);
}

double radA(NODE c1, double r1, NODE c2, double r2) {
    return acos((r1 * r1 + disSq(c1, c2) - r2 * r2) / (2 * r1 * sqrt(disSq(c1, c2))));
}

NODE polar(double a, double r) {
    return NODE(r * cos(a), r * sin(a));
}

vector<NODE> find(NODE c1, double r1, NODE c2, double r2) {
    vector<NODE> ret;

    if (sqrt(disSq(c1, c2)) > r1 + r2)
        return ret;

    double t = radT(c1, c2);
    double a = radA(c1, r1, c2, r2);

    NODE polar1 = polar(t + a, r1);
    NODE polar2 = polar(t - a, r1);

    ret.pb(NODE(c1.x + polar1.x, c1.y + polar1.y));
    if (abs(a) > eps)
        ret.pb(NODE(c1.x + polar2.x, c1.y + polar2.y));
    return ret;
}

signed main() {
    NODE A, B;
    double r1, r2;

    cin >> A.x >> A.y >> r1 >> B.x >> B.y >> r2;

    if (abs(A.x - B.x) < eps && abs(A.y - B.y) < eps && abs(r1 - r2) < eps) {
        cout << "無限多個焦點\n";
        return 0;
    }

    vector<NODE> ans = find(A, r1, B, r2);

    if (ans.size() == 0)
        cout << "沒有焦點\n";
    else {
        for (int i = 0; i < ans.size(); i++)
            cout << fixed << setprecision(6)
                 << "(" << ans[i].x << ", " << ans[i].y << ")\n";
    }

    return 0;
}
