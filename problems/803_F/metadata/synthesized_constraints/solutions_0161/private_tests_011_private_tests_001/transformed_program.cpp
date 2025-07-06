#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 100000 + 7;
const long long int MOD = 1e09 + 7;
int v[MAXN], all[MAXN], f[MAXN], ans[MAXN];

// Check performance bottlenecks
void check_large_max_element_invariant(int mx) {
    if (mx >= 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum element is very large!" << endl;
        abort();
    }
}

void check_high_divisor_frequency_invariant(int divisorCount) {
    if (divisorCount >= 1000) {  // Arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - high divisor frequency!" << endl;
        abort();
    }
}

void check_extensive_power_of_twos_invariant(int frequency) {
    if (frequency >= 1000) {  // Arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - extensive power of twos usage!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    all[0] = 1;
    int mx = 0;
    
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v[a]++;
        all[i] = (all[i - 1] << 1) % MOD;
        mx = max(mx, a);
    }

    // Check for large maximum element
    check_large_max_element_invariant(mx);

    for (int i = mx; i >= 1; i--) {
        for (int j = i; j <= mx; j += i) {
            f[i] += v[j];
            ans[i] = (ans[i] + MOD - ans[j]) % MOD;
        }

        // Check for high divisor frequency
        check_high_divisor_frequency_invariant(f[i]);

        ans[i] = (MOD + ans[i] + all[f[i]] - 1) % MOD;

        // Check for extensive power of twos usage
        check_extensive_power_of_twos_invariant(f[i]);
    }
    
    cout << ans[1] << endl;
    return 0;
}