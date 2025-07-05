#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9;
int n, w, m;
int a[20] = {1};
int _b[20], *const b = _b + 1;

void check_small_base_large_mass(int w, long long m) {
    if (w <= 4 && m > 1e8) {
        cerr << "Warning: Performance bottleneck condition triggered - small base with large mass!" << endl;
        abort();
    }
}

void check_exponential_permutations(int w, long long m) {
    if (w == 4 && m > 1e8) {
        cerr << "Warning: Performance bottleneck condition triggered - exponential permutations with base 4!" << endl;
        abort();
    }
}

void init() {
    long long p = 1;
    for (n = 1; (p *= w) <= N; ++n) a[n] = p;
}

bool check4() {
    if (w <= 3) return true;
    init();
    while (true) {
        long long x = 0;
        for (int i = 0; i < n; ++i)
            if (b[i] == 1)
                x += a[i];
            else if (b[i] == 2)
                x -= a[i];
        if (x == m || 1073741824ll - x == m) return true;
        int p = n - 1;
        while (b[p] == 2) --p;
        if (p == -1) break;
        for (++b[p++]; p < n; ++p) b[p] = 0;
    }
    return false;
}

bool check() {
    if (w <= 3) return true;
    init();
    if (w == 4) return check4();
    while (true) {
        long long x = 0;
        for (int i = 0; i < n; ++i)
            if (b[i] == 1)
                x += a[i];
            else if (b[i] == 2)
                x -= a[i];
        if (x == m) return true;
        int p = n - 1;
        while (b[p] == 2) --p;
        if (p == -1) break;
        for (++b[p++]; p < n; ++p) b[p] = 0;
    }
    return false;
}

int main() {
    scanf("%d%d", &w, &m);

    // Check for performance bottlenecks after reading inputs
    check_small_base_large_mass(w, m);
    check_exponential_permutations(w, m);

    puts(check() ? "YES" : "NO");
    return 0;
}