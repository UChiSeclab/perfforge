#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_large_n_invariant(int n) {
    if (n > 100000000) { // Arbitrary threshold based on the problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - large n value!" << endl;
        abort();
    }
}

void check_large_ai_invariant(const vector<pair<int, int>>& containers) {
    for (const auto& container : containers) {
        if (container.second > 50000000) { // Arbitrary threshold based on the problem constraints
            cerr << "Warning: Performance bottleneck condition triggered - large a[i] value!" << endl;
            abort();
        }
    }
}

void check_sorting_invariant(const vector<pair<int, int>>& containers) {
    bool extreme = false;
    for (size_t i = 1; i < containers.size(); ++i) {
        if (containers[i-1].first < containers[i].first) {
            extreme = true;
            break;
        }
    }
    if (extreme) {
        cerr << "Warning: Performance bottleneck condition triggered - sorting overhead!" << endl;
        abort();
    }
}

void check_prioritization_invariant(const vector<pair<int, int>>& containers) {
    for (const auto& container : containers) {
        if (container.first < -8) { // Since bi ranges from 1 to 10, -8 is a threshold for high bi
            cerr << "Warning: Performance bottleneck condition triggered - prioritization issue!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    // Check large n invariant
    check_large_n_invariant(n);

    vector<pair<int, int>> containers;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        containers.push_back({-b, a});
    }

    // Check large a[i] invariant
    check_large_ai_invariant(containers);

    // Sort containers by the number of matches per box (descending order)
    sort(containers.begin(), containers.end());

    // Check sorting invariant
    check_sorting_invariant(containers);

    // Check prioritization invariant
    check_prioritization_invariant(containers);

    int total = 0;
    int mark = 0;
    for (int i = 0; i < containers.size(); i++) {
        for (int j = 0; j < containers[i].second; j++) {
            n--;
            total -= containers[i].first;
            if (n == 0) {
                mark = 1;
                break;
            }
        }
        if (mark) break;
    }
    cout << total;
}