#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_sieve_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to high iteration count in sieve loop!" << endl;
        abort();
    }
}

void check_map_operations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive map operations with large y!" << endl;
        abort();
    }
}

void check_decrementing_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to prolonged decrementing loop!" << endl;
        abort();
    }
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int p, y, i;
    cin >> p >> y;

    // Check if y is much larger than p and might cause performance issues in loops
    check_sieve_invariant(y > p * p);

    if (p == y) {
        cout << -1;
        return 0;
    }

    map<int, vector<int> > grass;
    for (i = 2; i * i <= y && i <= p; i++) {
        grass[(y / i) * i].push_back(i);
    }

    // Check map growth due to large y
    check_map_operations_invariant(grass.size() > 100000); // Hypothetical threshold for a large map size

    for (i = y; i > p; i--) {
        if (grass.find(i) != grass.end()) {
            for (int k : grass[i]) {
                grass[i - k].push_back(k);
            }
        } else {
            cout << i << "\n";
            return 0;
        }

        // Check prolonged decrementing loop
        check_decrementing_loop_invariant((y - i) > 100000); // Hypothetical threshold for excessive decrementing
    }
    
    cout << -1;
}