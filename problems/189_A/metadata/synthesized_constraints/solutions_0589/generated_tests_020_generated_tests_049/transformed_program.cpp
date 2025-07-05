#include <bits/stdc++.h>
using namespace std;

// Check for large n causing performance issues due to exhaustive search
void check_large_n_combination_invariant(int n) {
    if (n > 1000) {  // Arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered due to large n with combination checks!" << endl;
        abort();
    }
}

int main() {
    int n, a, b, c, d = 1, e = 2, f = 3, i, j, h = 0, k = 0, l = 0, m = 0, o = 0,
                  p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0,
                  y = 0;
    cin >> n >> a >> b >> c;

    // Check for performance bottleneck condition based on n
    check_large_n_combination_invariant(n);

    if (a <= b && a <= c)
        j = a;
    else if (b <= a && b <= c)
        j = b;
    else if (c <= a && c <= b)
        j = c;
    if (n % j != 0) {
        if (n == a || n == b || n == c) {
            if (a == b + c || b == c + a || c == a + b) {
            } else {
                o++;
                s = d;
            }
        }
        if (n == a + b || n == b + c || n == a + c) {
            o++;
            s = e;
        }
        if (n == a + b + c) {
            o++;
            s = f;
        }
    }
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if ((i * a) + (j * b) == n) {
                p = i + j;
                if (p > k) k = p;
            }
            if ((i * b) + (j * c) == n) {
                q = i + j;
                if (q > l) l = q;
            }
            if ((i * c) + (j * a) == n) {
                r = i + j;
                if (r > m) m = r;
            }
            if ((i * a) + (j * b) + c == n) {
                t = i + j + 1;
                if (t > u) u = t;
            }
            if ((i * b) + (j * c) + a == n) {
                v = i + j + 1;
                if (v > w) w = v;
            }
            if ((i * c) + (j * a) + b == n) {
                x = i + j + 1;
                if (x > y) y = x;
            }
        }
    }
    if (k > s || l > s || m > s || u > s || w > s || y > s) {
        if (k >= l && k >= m && k >= u && k >= w && k >= y)
            cout << k;
        else if (l >= k && l >= m && l >= u && l >= w && l >= y)
            cout << l;
        else if (m >= k && m >= l && m >= u && m >= w && m >= y)
            cout << m;
        else if (u >= k && u >= l && u >= w && u >= y)
            cout << u;
        else if (w >= k && w >= l && w >= u && w >= y)
            cout << w;
        else if (y >= k && y >= l && y >= u && y >= w)
            cout << y;
    } else {
        cout << s;
    }
    return 0;
}