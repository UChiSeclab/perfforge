#include <bits/stdc++.h>
using namespace std;

void check_map_size_invariant(int mapSize, int threshold) {
    if (mapSize > threshold) {
        cerr << "Warning: Performance bottleneck triggered - map data structure too large!" << endl;
        abort();
    }
}

void check_loop_iterations_invariant(int n, int limit) {
    if (n > limit) {
        cerr << "Warning: Performance bottleneck triggered - too many outer loop iterations!" << endl;
        abort();
    }
}

void check_combination_complexity_invariant(int uniqueCombinations, int threshold) {
    if (uniqueCombinations > threshold) {
        cerr << "Warning: Performance bottleneck triggered - excessive unique combinations!" << endl;
        abort();
    }
}

const int base = 1000000007;
int n, k, res = 0;
pair<int, int> a[103];
map<int, int> b, c;
map<int, int>::iterator it;

int main() {
    int i, j;
    cin >> n >> k;
    
    // Check for too many outer loop iterations
    check_loop_iterations_invariant(n, 100);  // Given n <= 100, checking the upper limit

    for (i = 1; i <= n; i++) cin >> a[i].first;
    for (i = 1; i <= n; i++) {
        cin >> a[i].second;
        a[i].second = a[i].first - k * a[i].second;
    }
    b[0] = 0;
    for (i = 1; i <= n; i++) {
        // Check for map size growth
        check_map_size_invariant(b.size(), 1000);  // Arbitrary threshold based on expected growth

        for (it = (c = b).begin(); it != c.end(); it++) {
            b[it->first + a[i].second] =
                max(b[it->first + a[i].second], a[i].first + it->second);
        }
    }
    
    // Check for unique combination complexity
    check_combination_complexity_invariant(b.size(), 1000);  // Arbitrary threshold based on expected complexity

    if (b[0])
        cout << b[0];
    else
        cout << -1;
    return 0;
}