#include <bits/stdc++.h>
using namespace std;

long double solve(int s1, int i1, int s2, int i2) {
    if (i1 > s1 || i2 > s2) return 0;
    int pt1 = s1, pt2 = s2, pt3 = i1 + i2, pt4 = s1 + s2 - (i1 + i2);
    priority_queue<int> values1;
    values1.push(pt1);
    values1.push(pt2);
    values1.push(pt3);
    values1.push(pt4);
    int pt5 = i1, pt6 = s1 - i1, pt7 = i2, pt8 = s2 - i2, pt9 = s1 + s2;
    priority_queue<int> values2;
    values2.push(pt5);
    values2.push(pt6);
    values2.push(pt7);
    values2.push(pt8);
    values2.push(pt9);
    long double ans = 1;
    while (values1.size() || values2.size()) {
        if (values1.size()) {
            int have = values1.top();
            values1.pop();
            if (have == 0) continue;
            ans *= have;
            if (have != 1) values1.push(have - 1);
        }
        if (values2.size()) {
            int have = values2.top();
            values2.pop();
            if (have == 0) continue;
            ans /= have;
            if (have != 1) values2.push(have - 1);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        if (k == i)
            s1 = a;
        else
            s2 += a;
    }
    s1--;
    n--;

    // Insert the performance checkers here
    check_repeated_calculations(s1, s2, n);
    check_priority_queue_operations(s2);
    check_combinatorial_possibilities(s1, s2, n);

    if (s1 + s2 < n) {
        cout << -1;
        return 0;
    }

    long double prob = 0;
    for (int i = 1; i <= n; i++) {
        long double val = solve(s1, i, s2, n - i);
        prob += val;
    }
    cout << fixed << setprecision(8) << prob;
    return 0;
}