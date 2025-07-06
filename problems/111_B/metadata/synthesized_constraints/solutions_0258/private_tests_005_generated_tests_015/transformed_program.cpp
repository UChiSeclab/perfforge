#include <bits/stdc++.h>
using namespace std;

// Checker for high divisor count
void check_divisor_count_invariant(int divisorCount) {
    if (divisorCount > 1000) { // Arbitrary threshold based on potential high divisor counts
        cerr << "Warning: Performance bottleneck condition triggered due to high divisor count!" << endl;
        abort();
    }
}

// Checker for large map size
void check_map_size_invariant(const unordered_map<int, set<int>>& mm) {
    if (mm.size() > 50000) { // Arbitrary threshold based on potential growth
        cerr << "Warning: Performance bottleneck condition triggered due to large map size!" << endl;
        abort();
    }
}

// Checker for extensive prior divisor checks
void check_prior_divisor_checks(size_t factorSize, const set<int>& fact) {
    if (factorSize > 500) { // Arbitrary threshold for factor size
        cerr << "Warning: Performance bottleneck condition triggered due to extensive prior divisor checks!" << endl;
        abort();
    }
}

unordered_map<int, set<int> > mm;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        set<int> fact;

        int r = i - y, ans = 0;
        
        // Calculate divisors and check the count
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                fact.insert(j);
                if (x / j != j) fact.insert(x / j);
            }
        }

        check_divisor_count_invariant(fact.size()); // Check divisor count

        if (y == 0) {
            cout << (int)fact.size() << '\n';
        } else {
            int ans = 0;
            check_prior_divisor_checks(fact.size(), fact); // Check prior divisor usage

            for (auto m : fact) {
                int r = i - y;
                auto it = mm[m].lower_bound(r);
                if (it != mm[m].end() && *it >= r) continue;
                ans++;
            }
            cout << ans << '\n';
        }

        for (auto m : fact) mm[m].insert(i);

        check_map_size_invariant(mm); // Check map size
    }
    return 0;
}