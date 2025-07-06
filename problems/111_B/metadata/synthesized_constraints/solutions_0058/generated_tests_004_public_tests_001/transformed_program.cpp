#include <bits/stdc++.h>
using namespace std;

void check_divisor_count_invariant(int num, int divisor_threshold) {
    int divisor_count = 0;
    for (int j = 1; j * j <= num; j++) {
        if (num % j == 0) {
            divisor_count++;
            if (num / j != j) divisor_count++;
        }
    }
    if (divisor_count > divisor_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of divisors!" << endl;
        abort();
    }
}

void check_map_size_invariant(const map<int, set<int>>& m, int map_size_threshold) {
    if (m.size() > map_size_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large map size!" << endl;
        abort();
    }
}

void check_query_characteristics_invariant(int i, int yi, int range_threshold) {
    if (yi < range_threshold && i > range_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to small yi compared to i!" << endl;
        abort();
    }
}

map<int, set<int>> m;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        int y;
        cin >> a[i] >> y;

        // Check query characteristics invariant
        check_query_characteristics_invariant(i, y, 10);

        vector<int> div;

        // Check divisor count invariant
        check_divisor_count_invariant(a[i], 20); // Arbitrary threshold for demonstration

        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                div.push_back(j);
                if (a[i] / j != j) div.push_back(a[i] / j);
            }
        }
        int res = 0;
        for (int d : div) {
            if (m[d].lower_bound(i - y) == m[d].end()) res++;
        }
        cout << res << '\n';
        for (int d : div) m[d].insert(i);

        // Check map size invariant
        check_map_size_invariant(m, 100); // Arbitrary threshold for demonstration
    }
}