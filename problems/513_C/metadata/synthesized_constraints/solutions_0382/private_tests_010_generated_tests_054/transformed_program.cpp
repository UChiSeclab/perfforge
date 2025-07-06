#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;
struct bid {
  int l, r;
} b[maxn];
int n;
int a[maxn];
double ans = 0.0;
int price;
double pos = 0.0;
bool flag;

void check_overlapping_bid_ranges(int n, const bid* b) {
    int overlap_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (b[i].r >= b[j].l && b[i].l <= b[j].r) {
                overlap_count++;
            }
        }
    }
    if (overlap_count > n - 1) {
        cerr << "Warning: Performance bottleneck due to overlapping bid ranges!" << endl;
        abort();
    }
}

void check_wide_bid_ranges(int n, const bid* b) {
    for (int i = 0; i < n; ++i) {
        if (b[i].r - b[i].l > 5000) {
            cerr << "Warning: Performance bottleneck due to wide bid range for company " << i + 1 << "!" << endl;
            abort();
        }
    }
}

void check_price_variability(int minp, int maxp) {
    if (maxp - minp > 8000) {
        cerr << "Warning: Performance bottleneck due to high price variability!" << endl;
        abort();
    }
}

void solve(int p) {
    if (p == n) {
        int num = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 2) num++;
        if (flag && num < 1) return;
        if ((!flag) && num < 2) return;
        double tmp = 1.0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                tmp *= ((double)(b[i].r - max(price, b[i].l - 1))) / (b[i].r - b[i].l + 1);
            }
            if (a[i] == 2) {
                tmp *= 1.0 / (b[i].r - b[i].l + 1);
            }
            if (a[i] == 3) {
                tmp *= (double)(min(price, b[i].r + 1) - b[i].l) / (b[i].r - b[i].l + 1);
            }
        }
        pos += tmp;
        return;
    }
    if ((b[p].r > price) && (!flag)) {
        flag = true;
        a[p] = 1;
        solve(p + 1);
        flag = false;
    }
    if (b[p].l < price) {
        a[p] = 3;
        solve(p + 1);
    }
    if (b[p].l <= price && b[p].r >= price) {
        a[p] = 2;
        solve(p + 1);
    }
}

int main() {
    scanf("%d", &n);
    int minp = 20000, maxp = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &b[i].l, &b[i].r);
        if (minp > b[i].l) minp = b[i].l;
        if (maxp < b[i].r) maxp = b[i].r;
    }

    // Check for potential performance bottlenecks
    check_overlapping_bid_ranges(n, b);
    check_wide_bid_ranges(n, b);
    check_price_variability(minp, maxp);

    for (int i = minp; i <= maxp; i++) {
        flag = false;
        price = i;
        pos = 0.0;
        solve(0);
        ans += pos * i;
    }
    printf("%.9f\n", ans);
    return 0;
}