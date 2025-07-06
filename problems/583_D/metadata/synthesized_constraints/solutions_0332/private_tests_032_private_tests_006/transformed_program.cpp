#include <bits/stdc++.h>
using namespace std;

// Check if `T` is significantly larger than `n`.
void check_large_T_vs_n(int T, int n) {
    if (T > 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - T is significantly larger than n!" << endl;
        abort();
    }
}

// Check for a high degree of uniqueness in the input array `a`.
void check_high_uniqueness(const int a[], int n) {
    set<int> unique_elements(a, a + n);
    if (unique_elements.size() > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high degree of uniqueness in input array!" << endl;
        abort();
    }
}

// Check if `n` is at its maximum constraint and involves diverse values.
void check_max_n_constraint(int n, const int a[]) {
    set<int> unique_elements(a, a + n);
    if (n == 100 && unique_elements.size() > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - max n constraint with diverse input!" << endl;
        abort();
    }
}

int lisLength(int a[], int n, int mn, int mx) {
    vector<int> lis;
    for (int i = 0; i < n; i++)
        if (a[i] >= mn && a[i] <= mx) {
            vector<int>::iterator it = upper_bound(lis.begin(), lis.end(), a[i]);
            if (it == lis.end())
                lis.push_back(a[i]);
            else
                *it = a[i];
        }
    return lis.size();
}

int main() {
    int n, t;
    scanf("%d", &n);
    scanf("%d", &t);
    int a[110], b[20020];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // Insert invariant checks after input is read.
    check_large_T_vs_n(t, n);
    check_high_uniqueness(a, n);
    check_max_n_constraint(n, a);

    for (int i = 0; i < min(t, n); i++)
        for (int j = 0; j < n; j++) b[i * n + j] = a[j];
    if (t <= n)
        printf("%d\n", lisLength(b, t * n, INT_MIN, INT_MAX));
    else if (t <= 2 * n) {
        for (int i = n; i < t; i++)
            for (int j = 0; j < n; j++) b[i * n + j] = a[j];
        printf("%d\n", lisLength(b, t * n, INT_MIN, INT_MAX));
    } else {
        int cnt[330] = {0};
        for (int i = 0; i < n; i++) cnt[a[i]]++;
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, lisLength(b, n * n, INT_MIN, a[i]) +
                             cnt[a[i]] * (t - 2 * n) +
                             lisLength(b, n * n, a[i], INT_MAX));
        printf("%d\n", ans);
    }
    return 0;
}