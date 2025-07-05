#include <bits/stdc++.h>
using namespace std;

void check_frequent_iterations_invariant(long long a[], int n) {
    int small_value_count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 10) {
            small_value_count++;
        }
    }
    if (small_value_count > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent small leading values!" << endl;
        abort();
    }
}

void check_dense_array_invariant(long long a[], int n) {
    unordered_map<long long, int> frequency;
    for (int i = 0; i < n; ++i) {
        frequency[a[i]]++;
    }
    for (const auto& entry : frequency) {
        if (entry.second > n / 4) {
            cerr << "Warning: Performance bottleneck condition triggered - dense array with repeated elements!" << endl;
            abort();
        }
    }
}

void check_secondary_card_invariant(long long a[], int n) {
    for (int i = 0; i < n; ++i) {
        long long count = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && a[j] % a[i] == 0) {
                count++;
            }
        }
        if (count > n / 2) {
            cerr << "Warning: Performance bottleneck condition triggered - too many potential secondary cards!" << endl;
            abort();
        }
    }
}

long long a[200010];
int main() {
    long long n, bnd, tmp, ans, mx;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);

        // Insert checks after sorting
        check_frequent_iterations_invariant(a, n);
        check_dense_array_invariant(a, n);
        check_secondary_card_invariant(a, n);

        bnd = a[0] * 2;
        mx = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && a[i] == a[i - 1]) continue;
            tmp = 2;
            ans = 0;
            while (1) {
                if (a[i] * (tmp - 1) > 200010) {
                    break;
                }
                ans += (long long)((upper_bound(a, a + n, a[i] * tmp - 1) - a) -
                                   (upper_bound(a, a + n, a[i] * (tmp - 1) - 1) - a)) *
                       a[i] * (tmp - 1);
                ++tmp;
            }
            mx = max(mx, ans);
        }
        cout << mx << endl;
    }
    return 0;
}