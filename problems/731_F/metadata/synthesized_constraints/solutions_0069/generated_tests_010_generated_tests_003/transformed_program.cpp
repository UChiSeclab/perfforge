#include <bits/stdc++.h>
using namespace std;
long long n, a[((long long)201 * 1000)], res;

// Checker functions
void check_high_multiples_invariant(int a[], int n, int threshold) {
    int count[201000] = {0};
    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
    }
    for (int i = 0; i < 201000; ++i) {
        if (count[i] > threshold) {
            cerr << "Warning: Performance bottleneck condition triggered - high multiples iteration with frequent elements!" << endl;
            abort();
        }
    }
}

void check_common_small_values_invariant(int a[], int n, int small_value_threshold, int count_threshold) {
    int count[201000] = {0};
    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
    }
    for (int i = 1; i <= small_value_threshold; ++i) {
        if (count[i] > count_threshold) {
            cerr << "Warning: Performance bottleneck condition triggered - interaction with common small power values!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // Insert checks to catch potential bottlenecks
    check_high_multiples_invariant(a, n, 10);  // Example threshold for frequent element detection
    check_common_small_values_invariant(a, n, 10, 10);  // Example thresholds for small values
    
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        long long ans = 0;
        if (i && a[i] == a[i - 1]) continue;
        for (long long j = a[i]; j < ((long long)201 * 1000); j += a[i]) {
            long long x = (lower_bound(a, a + n, j) - a) -
                          (lower_bound(a, a + n, j + a[i]) - a);
            ans += (-x) * j;
        }
        res = max(ans, res);
    }
    cout << res;
}