#include <bits/stdc++.h>
using namespace std;

// Function to check high divisor count
void check_divisor_count_invariant(int x, int divisor_count) {
    if (divisor_count > 100) { // Threshold based on reasonable divisor count for large `x`
        cerr << "Warning: High divisor count for x = " << x << ", potential slow execution!" << endl;
        abort();
    }
}

// Function to check excessive set operations
void check_set_operation_invariant(int set_operations) {
    if (set_operations > 1000) { // Threshold indicating excessive set operations
        cerr << "Warning: Excessive set operations, potential performance degradation!" << endl;
        abort();
    }
}

// Function to check large map size
void check_map_size_invariant(const map<int, set<int>>& m) {
    if (m.size() > 1000) { // Sample threshold for map size
        cerr << "Warning: Large map size, potential slowdown!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, set<int>> m;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        int divisor_count = 0;
        int set_operations = 0;
        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                ++divisor_count;
                if (j * j != x) {
                    ++divisor_count;
                }
                if (m[j].upper_bound(i - y - 1) == m[j].end()) {
                    ++ans;
                    ++set_operations;
                }
                if (j * j != x && m[x / j].upper_bound(i - y - 1) == m[x / j].end()) {
                    ++ans;
                    ++set_operations;
                }
            }
        }
        check_divisor_count_invariant(x, divisor_count); // Check for high divisor count
        check_set_operation_invariant(set_operations);   // Check for excessive set operations

        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                m[j].insert(i);
                m[x / j].insert(i);
            }
        }
        
        check_map_size_invariant(m); // Check for large map size
        
        cout << ans << '\n';
    }
}