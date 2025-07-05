#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long ans[100010];
long long t, n, tot;
map<long long, bool> ma;

// Invariant check functions
void check_large_n_invariant(long long n) {
    if (n >= 1e9) { // Threshold chosen based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - large n value!" << endl;
        abort();
    }
}

void check_dense_divisor_invariant(long long tot) {
    if (tot > 1000) { // Arbitrary threshold for too many unique divisors
        cerr << "Warning: Performance bottleneck condition triggered - too many unique divisors!" << endl;
        abort();
    }
}

void check_loop_map_interaction(int loopIterations, long long max_map_size) {
    if (loopIterations > 30000 || max_map_size > 1000) { // Threshold for iterations and map size
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop or map usage!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ma.clear();
        tot = 0;
        cin >> n;

        // Check for large n
        check_large_n_invariant(n);

        ans[++tot] = 0;
        int loopIterations = 0;
        long long max_map_size = 0;
        
        for (int i = 1; i * i <= n; ++i) {
            long long a = n / i;
            long long b = n / a;
            loopIterations++;
            if (!ma[a]) {
                ma[a] = 1;
                ans[++tot] = a;
            }
            if (!ma[b]) {
                ma[b] = 1;
                ans[++tot] = b;
            }
            max_map_size = ma.size();
        }
        
        // Check for loop and map interaction
        check_loop_map_interaction(loopIterations, max_map_size);

        sort(ans + 1, ans + 1 + tot);

        // Check for too many unique divisors
        check_dense_divisor_invariant(tot);

        cout << tot << "\n";
        for (int i = 1; i <= tot; ++i) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}