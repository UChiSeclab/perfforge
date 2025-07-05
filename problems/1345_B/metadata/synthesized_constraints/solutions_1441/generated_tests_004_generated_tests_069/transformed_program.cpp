#include <bits/stdc++.h>
using namespace std;

// Checker for large maximum card count across test cases
void check_max_cards_invariant(long long max) {
    if (max > 1000000) {  // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered due to large max card count!" << endl;
        abort();
    }
}

// Checker for large `n` in a single test case
void check_large_n_invariant(long long n) {
    if (n > 1000000) {  // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered due to large n value!" << endl;
        abort();
    }
}

int main() {
    long long t, max = 0, a;
    cin >> t;
    vector<long long> v, cards;
    for (int i = 0; i < t; i++) {
        cin >> a;
        v.push_back(a);
        if (a > max) max = v[i];
        check_large_n_invariant(a); // Check for large `n` in a single test case
    }
    check_max_cards_invariant(max); // Check for large maximum card count

    for (int i = 1; ((3 * i * i + i) / 2) <= max; i++) {
        cards.push_back((3 * i * i + i) / 2);
    }
    for (int i = 0; i < v.size(); i++) {
        int count = 0;
        while (v[i] >= cards[0]) {
            auto upper1 = upper_bound(cards.begin(), cards.end(), v[i]);
            if (upper1 == cards.end()) {
            } else {
            }
            v[i] -= *(--upper1);
            count++;
        }
        cout << count << "\n";
    }
}