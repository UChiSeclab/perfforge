#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 10, inf = 1000111222;
int n, m;
int a[max_n];
int b[max_n];

void check_upper_bound_use(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive use of upper_bound in nested loops!" << endl;
        abort();
    }
}

void check_large_uniform_distribution(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of notes with potential uniform distribution!" << endl;
        abort();
    }
}

void check_high_variability(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high variability in string base values!" << endl;
        abort();
    }
}

bool check1(int l, int r) {
    int p = 0;
    for (int i = 0; p < m && i < n; i++) {
        if (b[p] < a[i] + l) {
            return 0;
        }
        p = upper_bound(b + p, b + m, a[i] + r) - b;
    }
    return p == m;
}

bool check(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            {
                int l = b[j] - a[i];
                int r = l + x;
                if (check1(l, r)) {
                    return 1;
                }
            }
            {
                int r = b[j] - a[i];
                int l = r - x;
                if (check1(l, r)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    n = 6;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    // Check for high variability in string base values
    int max_base_value = *max_element(a, a + n);
    int min_base_value = *min_element(a, a + n);
    check_high_variability(max_base_value - min_base_value > 100000); // Arbitrary threshold

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b, b + m);

    // Check for large uniform distribution
    check_large_uniform_distribution(m > 50000); // Arbitrary threshold for large m

    int l = 0, r = 1e9;
    while (r - l > 0) {
        int m = (l + r) / 2;

        // Check for excessive use of upper_bound
        check_upper_bound_use(n * m > 1000000); // Arbitrary threshold for nested loops

        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << "\n";
}