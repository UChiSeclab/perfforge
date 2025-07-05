#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = unsigned long long int;

// Performance checkers
void check_large_k_invariant(ll n, ll k) {
    if (k > (n * (n - 1)) / 4) { // Check if k is relatively large
        cerr << "Warning: Performance bottleneck condition triggered - large k potentially causing excessive loop iterations!" << endl;
        abort();
    }
}

void check_sequence_construction_invariant(ll n, ll k) {
    if (k > (n * (n - 1)) / 4) { // Check if k results in positioning 'b's near the string end
        cerr << "Warning: Performance bottleneck condition triggered - sequence construction requires many iterations!" << endl;
        abort();
    }
}

void check_decrement_operations_invariant(ll n, ll k) {
    if (k > (n * (n - 1)) / 4) { // Ensure k is large enough to necessitate many decrements
        cerr << "Warning: Performance bottleneck condition triggered - excessive k decrement operations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        // Insert performance checks
        check_large_k_invariant(n, k);
        check_sequence_construction_invariant(n, k);
        check_decrement_operations_invariant(n, k);

        string s(n, 'a');
        for (ll i = n - 2; i >= 0; i--) {
            if (k <= n - i - 1) {
                s[i] = 'b';
                s[n - k] = 'b';
                cout << s << '\n';
                break;
            }
            k -= n - i - 1;
        }
    }
    return 0;
}