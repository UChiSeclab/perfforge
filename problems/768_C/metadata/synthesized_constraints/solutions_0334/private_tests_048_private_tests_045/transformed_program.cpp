#include <bits/stdc++.h>
const int N = (int)4e3 + 228;
using namespace std;
int n, a[N], new_a[N], k, x;

void check_high_k_invariant(int k) {
    if (k > 10000) { // Arbitrary threshold to identify potentially high iteration counts
        cerr << "Warning: Performance bottleneck condition triggered due to high k!" << endl;
        abort();
    }
}

void check_dense_population_invariant(int a[], int size) {
    int non_zero_count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] != 0) {
            non_zero_count++;
        }
    }
    if (non_zero_count > 2000) { // Threshold assumes a significant number of non-zero entries
        cerr << "Warning: Performance bottleneck due to dense strength distribution!" << endl;
        abort();
    }
}

void check_recurrent_updates_invariant(int k, int iteration_threshold) {
    if (k > iteration_threshold) {
        cerr << "Warning: Performance bottleneck due to high recurrent updates!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &x);
    check_high_k_invariant(k); // Check condition after input

    for (int i = 1; i <= n; i++) {
        int y;
        scanf("%d", &y);
        a[y]++;
    }
    
    check_dense_population_invariant(a, N); // Check dense distribution

    int iteration_threshold = 50000; // Threshold for recurrent updates check
    check_recurrent_updates_invariant(k, iteration_threshold);

    for (int i = 1; i <= k; i++) {
        int cur = 0;
        for (int j = 0; j <= 4000; j++) {
            if (a[j]) {
                if (cur % 2 == 0) {
                    new_a[j ^ x] += (a[j] + 1) / 2;
                    new_a[j] += a[j] / 2;
                } else {
                    new_a[j ^ x] += a[j] / 2;
                    new_a[j] += (a[j] + 1) / 2;
                }
                cur += a[j];
            }
        }
        for (int j = 0; j <= 4000; j++) {
            a[j] = new_a[j];
            new_a[j] = 0;
        }
    }

    int mn = N, mx = -1;
    for (int i = 0; i < N; i++) {
        if (a[i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    cout << mx << ' ' << mn << endl;
    return 0;
}