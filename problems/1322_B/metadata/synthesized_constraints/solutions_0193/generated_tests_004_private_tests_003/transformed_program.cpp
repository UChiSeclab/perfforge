#include <bits/stdc++.h>
using namespace std;

// Checker for excessive pairwise operation
void check_pairwise_operations_invariant(long long n, long long maxAllowedSize) {
    if (n > maxAllowedSize) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive pairwise operations!" << endl;
        abort();
    }
}

// Checker for repeated sorting
void check_repeated_sorting_invariant(long long numSorts, long long n) {
    if (numSorts > 30 && n > 70) { // Threshold for repeated sorting cost
        cerr << "Warning: Performance bottleneck condition triggered - repeated sorting operations!" << endl;
        abort();
    }
}

// Checker for large input size
void check_input_size_invariant(long long n, long long threshold) {
    if (n > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large input size!" << endl;
        abort();
    }
}

long long need(long long i, vector<long long> &b, long long pos_in_v) {
    long long first = upper_bound(b.begin() + pos_in_v + 1, b.end(), (1ll << (i + 1)) - b[pos_in_v] - 1) - b.begin() - pos_in_v;
    first -= lower_bound(b.begin() + pos_in_v + 1, b.end(), (1ll << i) - b[pos_in_v]) - b.begin();
    long long second = upper_bound(b.begin() + pos_in_v + 1, b.end(), (1ll << (i + 2)) - 2 - b[pos_in_v]) - b.begin() - pos_in_v;
    second -= lower_bound(b.begin() + pos_in_v + 1, b.end(), (1ll << (i + 1)) + (1ll << i) - b[pos_in_v]) - b.begin();
    return first + second;
}

bool add(long long bit, vector<long long> a) {
    vector<long long> b((long long)a.size());
    long long n = (long long)a.size();
    for (long long i = 0; i < n; i++) {
        b[i] = a[i] % (1ll << (bit + 1));
    }
    sort(b.begin(), b.end());
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
        cnt += need(bit, b, i);
    }
    return cnt % 2;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &z : a) cin >> z;
    
    // Insert checkers
    check_pairwise_operations_invariant(n, 80); // Example threshold for pairwise operations
    check_input_size_invariant(n, 90); // Example threshold for large input size

    long long ans = 0;
    for (long long i = 0; i < 32; i++) {
        // Check repeated sorting (in `add` function)
        check_repeated_sorting_invariant(i, n);
        if (add(i, a)) {
            ans += (1ll << i);
        }
    }
    cout << ans;
    return 0;
}