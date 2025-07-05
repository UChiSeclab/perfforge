#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_large_grid_invariant(long long n, long long c) {
    if (n > 100000000 && c > n * n / 2) {
        cerr << "Warning: Potential slow execution due to large grid size and high c relative to n^2!" << endl;
        abort();
    }
}

void check_initial_position_invariant(long long x, long long y, long long n) {
    if ((x == 1 || x == n || y == 1 || y == n) && n > 100000000) {
        cerr << "Warning: Potential slow execution due to initial position near grid edge on a large grid!" << endl;
        abort();
    }
}

void check_diffusion_requirement_invariant(long long n, long long c) {
    if (c > n) {
        cerr << "Warning: Potential slow execution due to high diffusion requirement (c > n)!" << endl;
        abort();
    }
}

int main() {
    long long n, x, y, c, ans = -1;
    long long maxx, maxy, minx, miny;
    long long s = 0;
    cin >> n >> x >> y >> c;

    // Insert checks after input
    check_large_grid_invariant(n, c);
    check_initial_position_invariant(x, y, n);
    check_diffusion_requirement_invariant(n, c);

    while (s < c) {
        ans++;
        maxx = x + ans;
        maxy = y + ans;
        minx = x - ans;
        miny = y - ans;
        s = 2 * ans * ans + (ans * 2 + 1);
        long long t1, t2, t3, t4;
        t1 = max(maxx - n, 0LL);
        t2 = max(maxy - n, 0LL);
        t3 = max(1 - minx, 0LL);
        t4 = max(1 - miny, 0LL);
        s -= t1 * t1;
        s -= t2 * t2;
        s -= t3 * t3;
        s -= t4 * t4;
        long long tt1, tt2, tt3, tt4;
        tt1 = max(t1 - (n + 1 - y), 0LL);
        tt2 = max(t1 - y, 0LL);
        tt3 = max(t3 - y, 0LL);
        tt4 = max(t3 - (n + 1 - y), 0LL);
        s += tt1 * (tt1 + 1LL) / 2LL;
        s += tt2 * (tt2 + 1LL) / 2LL;
        s += tt3 * (tt3 + 1LL) / 2LL;
        s += tt4 * (tt4 + 1LL) / 2LL;
    }

    cout << ans;
    return 0;
}