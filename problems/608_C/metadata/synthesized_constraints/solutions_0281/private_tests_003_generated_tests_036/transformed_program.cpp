#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_large_position_range(int max_pos, int n) {
    if (max_pos > 100 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - large position range compared to number of beacons!" << endl;
        abort();
    }
}

void check_sparse_distribution(int max_pos, int n) {
    if (n < 10 && max_pos > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse beacon distribution!" << endl;
        abort();
    }
}

void check_map_lookup_overhead(int max_pos, int n) {
    if (max_pos > 1000 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive map lookups!" << endl;
        abort();
    }
}

int main() {
    map<int, int> positions_to_beacons;
    int max_pos = 0, n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int position, power;
        cin >> position;
        cin >> power;
        positions_to_beacons.insert(make_pair(position, power));
        max_pos = max(max_pos, position + 1);
    }

    // Insert performance checks here
    check_large_position_range(max_pos, n);
    check_sparse_distribution(max_pos, n);
    check_map_lookup_overhead(max_pos, n);

    int *saved_to = new int[max_pos + 1];
    for (int i = 0; i <= max_pos; ++i) {
        saved_to[i] = 0;
    }
    if (positions_to_beacons.find(0) != positions_to_beacons.end()) {
        saved_to[0] = 1;
    }
    int max_saved = 0;
    for (int i = 1; i <= max_pos; i++) {
        auto beacon_pair = positions_to_beacons.find(i);
        if (beacon_pair != positions_to_beacons.end()) {
            int power = beacon_pair->second;
            if (power - i >= 0) {
                saved_to[i] = 1;
            } else {
                saved_to[i] = saved_to[i - power - 1] + 1;
            }
        } else {
            saved_to[i] = saved_to[i - 1];
        }
        max_saved = max(saved_to[i], max_saved);
    }
    int destroyed = n - max_saved;
    cout << destroyed << endl;
    return 0;
}