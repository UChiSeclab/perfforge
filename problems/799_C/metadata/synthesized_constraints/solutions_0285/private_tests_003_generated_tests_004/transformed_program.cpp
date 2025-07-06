#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, m, ans, maxc, maxd;
int a[maxn], b[maxn], s1[maxn], s2[maxn];
vector<int> t1, t2;

void check_large_budget_invariant(int c, int d) {
    if (c > 50000 || d > 50000) {  // Check for large budget causing lengthy calculations
        cerr << "Warning: Performance bottleneck condition triggered - Large budget causes lengthy calculations!" << endl;
        abort();
    }
}

void check_high_cost_beauty_invariant(int maxc, int maxd, int budgetC, int budgetD) {
    if ((maxc > 30000 && budgetC > 50000) || (maxd > 30000 && budgetD > 50000)) {  // Check for inefficiencies due to high beauty and cost
        cerr << "Warning: Performance bottleneck condition triggered - High beauty and cost create inefficiencies!" << endl;
        abort();
    }
}

int main() {
    int i, j, k, c, d;
    scanf("%d%d%d", &n, &c, &d);

    // Insert check after reading input values
    check_large_budget_invariant(c, d);

    for (i = 1; i <= n; ++i) {
        int v, p;
        string s;
        scanf("%d%d", &v, &p);
        cin >> s;
        if (s == "C") {
            if (p <= c) {
                maxc = max(maxc, v);
                a[p] = max(a[p], v);
                if (p * 2 == c) t1.push_back(v);
            }
        } else {
            if (p <= d) {
                maxd = max(maxd, v);
                b[p] = max(b[p], v);
                if (p * 2 == d) t2.push_back(v);
            }
        }
    }

    // Insert check before performing calculations with beauty values
    check_high_cost_beauty_invariant(maxc, maxd, c, d);

    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    int len1 = t1.size(), len2 = t2.size();
    if (len1 > 1) ans = max(ans, t1[len1 - 1] + t1[len1 - 2]);
    if (len2 > 1) ans = max(ans, t2[len2 - 1] + t2[len2 - 2]);
    if (maxc > 0 && maxd > 0) ans = maxc + maxd;
    for (i = 1; i <= c; ++i) {
        s1[i] = max(s1[i - 1], a[i]);
    }
    for (i = 1; i <= d; ++i) {
        s2[i] = max(s2[i - 1], b[i]);
    }
    for (i = c / 2 + 1; i < c; ++i) {
        if (a[i] > 0 && s1[c - i] > 0) ans = max(ans, a[i] + s1[c - i]);
    }
    for (i = 2; i < c / 2 + 1; ++i) {
        if (a[i] > 0 && s1[i - 1] > 0) ans = max(ans, a[i] + s1[i - 1]);
    }
    for (i = d / 2 + 1; i < d; ++i) {
        if (b[i] > 0 && s2[d - i] > 0) ans = max(ans, b[i] + s2[d - i]);
    }
    for (i = 2; i < d / 2 + 1; ++i) {
        if (b[i] > 0 && s2[i - 1] > 0) ans = max(ans, b[i] + s2[i - 1]);
    }
    printf("%d", ans);
    return 0;
}