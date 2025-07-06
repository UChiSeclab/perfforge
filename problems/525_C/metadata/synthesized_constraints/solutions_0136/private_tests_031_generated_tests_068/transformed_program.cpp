#include <bits/stdc++.h>
using namespace std;

void check_large_max_length_invariant(long long mx, long long average_length) {
    if (mx > 5 * average_length) {
        cerr << "Warning: Performance bottleneck due to large maximum stick length!" << endl;
        abort();
    }
}

void check_high_density_max_length_invariant(long long max_count, long long n) {
    if (max_count > n / 2) {
        cerr << "Warning: Performance bottleneck due to high density of maximum length sticks!" << endl;
        abort();
    }
}

void check_large_vector_operations_invariant(size_t vector_size, long long n) {
    if (vector_size > n / 2) {
        cerr << "Warning: Performance bottleneck due to repeated large vector operations!" << endl;
        abort();
    }
}

long long a[1000009];
vector<long long> v;

int main() {
    long long i, j, k, n, m;
    while (scanf("%lld", &n) == 1) {
        memset(a, 0, sizeof(a));
        v.clear();
        long long mx = 0;
        long long total_length = 0;
        
        for (i = 0; i < n; i++) {
            scanf("%lld", &k);
            mx = max(k, mx);
            a[k]++;
            total_length += k;
        }
        
        // Calculate average length
        long long average_length = total_length / n;
        
        // Check for large maximum stick length
        check_large_max_length_invariant(mx, average_length);
        
        // Check for high density of maximum length sticks
        check_high_density_max_length_invariant(a[mx], n);
        
        long long pre = 0;
        for (i = mx; i >= 1; i--) {
            if (pre) {
                if (a[i] % 2) {
                    a[i]++;
                    pre = 0;
                } else if (a[i] == 0)
                    pre = 0;
                else
                    pre = 1;
            } else {
                if (a[i] % 2) {
                    a[i]--;
                    pre = 1;
                } else
                    pre = 0;
            }
            a[i] /= 2;
        }
        
        long long ans = 0;
        for (i = mx; i >= 1; i--) {
            for (j = 0; j < a[i]; j++) {
                v.push_back(i);
            }
        }
        
        // Check for large vector operations
        check_large_vector_operations_invariant(v.size(), n);
        
        for (i = 0; i + 1 < v.size(); i += 2) {
            ans += v[i] * v[i + 1];
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}