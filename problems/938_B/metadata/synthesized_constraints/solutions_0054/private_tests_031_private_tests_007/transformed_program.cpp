#include <bits/stdc++.h>
using namespace std;

// Check for large distance between the first and last prize
void check_large_distance_invariant(long long first_prize, long long last_prize) {
    if ((last_prize - first_prize) > 500000) { // Assuming a large threshold for distance
        cerr << "Warning: Performance bottleneck condition triggered due to large distance between prizes!" << endl;
        abort();
    }
}

// Check for sparse distribution of prizes
void check_sparse_distribution_invariant(long long first_prize, long long last_prize, long long n) {
    if (n < 10 && (last_prize - first_prize) > 500000) { // Assuming sparsity implies fewer than 10 prizes over a large distance
        cerr << "Warning: Performance bottleneck condition triggered due to sparse prize distribution!" << endl;
        abort();
    }
}

int main() {
    long long n;
    cin >> n;
    vector<long long> prizes(n);
    for (long long i = 0; i < n; i++) {
        cin >> prizes[i];
    }

    // Insert checks after reading input
    check_large_distance_invariant(prizes.front(), prizes.back());
    check_sparse_distribution_invariant(prizes.front(), prizes.back(), n);

    // Original program logic
    long long s1 = 1, e1 = 1000000, cnt = 0, ans = 0;
    while (1) {
        ans++;
        s1++;
        if (binary_search(prizes.begin(), prizes.end(), s1)) cnt++;
        if (cnt == n || s1 == e1 - 1) break;
        e1--;
        if (binary_search(prizes.begin(), prizes.end(), e1)) cnt++;
        if (cnt == n || s1 == e1 - 1) break;
    }
    cout << ans << endl;
    return 0;
}