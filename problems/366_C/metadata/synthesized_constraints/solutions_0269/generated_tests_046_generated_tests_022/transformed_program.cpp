#include <bits/stdc++.h>
using namespace std;
const int base = 1000000007;
int n, k, res = 0;
pair<int, int> a[102];
map<int, int> b, c;
map<int, int>::iterator it;

// Checker function for map size
void check_map_size_invariant(size_t mapSize) {
    if (mapSize > 1000) { // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - map size too large!" << endl;
        abort();
    }
}

// Checker function for frequent updates
void check_frequent_updates(size_t updatesCount) {
    if (updatesCount > 10000) { // Threshold for excessive updates
        cerr << "Warning: Performance bottleneck condition triggered - too many updates!" << endl;
        abort();
    }
}

// Checker function for quadratic behavior
void check_quadratic_behavior(size_t iterationCount) {
    if (iterationCount > 5000) { // Threshold for excessive iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations!" << endl;
        abort();
    }
}

int main() {
    int i, j;
    cin >> n >> k;
    for (i = 1; i <= n; i++) cin >> a[i].first;
    for (i = 1; i <= n; i++) {
        cin >> a[i].second;
        a[i].second = a[i].first - k * a[i].second;
    }
    b[0] = 0;
    
    size_t updatesCount = 0;
    size_t iterationCount = 0;

    for (i = 1; i <= n; i++) {
        c = b;
        check_map_size_invariant(b.size()); // Check before the loop starts
        for (it = c.begin(); it != c.end(); it++) {
            iterationCount++;
            b[it->first + a[i].second] = max(b[it->first + a[i].second], a[i].first + it->second);
            updatesCount++;
        }

        check_frequent_updates(updatesCount); // Check after updates
    }

    check_quadratic_behavior(iterationCount); // Check after all iterations

    if (b[0])
        cout << b[0];
    else
        cout << -1;
    return 0;
}