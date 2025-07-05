#include <bits/stdc++.h>
using namespace std;

void check_k_max_invariant(int n, int k) {
    int max_k = (n * (n - 1)) / 2;
    if (k > max_k * 0.9) {  // Arbitrary threshold at 90% of maximum
        cerr << "Warning: Performance bottleneck condition triggered - k is close to maximum value!" << endl;
        abort();
    }
}

void check_large_n_k_invariant(int n, int k) {
    int max_k = (n * (n - 1)) / 2;
    if (n > 90000 && k > max_k * 0.8) {  // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - large n with high k!" << endl;
        abort();
    }
}

void check_inefficient_k_decrement(int n, int k, int i) {
    int decrement_size = n - i - 1;
    if (k > decrement_size * 1000) {  // Arbitrary multiplier
        cerr << "Warning: Performance bottleneck condition triggered - inefficient k decrement!" << endl;
        abort();
    }
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        
        // Check conditions after reading input
        check_k_max_invariant(n, k);
        check_large_n_k_invariant(n, k);
        
        string ans(n, 'a');
        
        for (int i = n - 2; i >= 0; i--) {
            check_inefficient_k_decrement(n, k, i); // Check inside loop but not in tight spot
            if (k <= n - i - 1) {
                ans[i] = ans[n - k] = 'b';
                break;
            }
            k -= (n - i - 1);
        }
        
        cout << ans << endl;
    }
    return 0;
}