#include <bits/stdc++.h>
using namespace std;

void check_nested_degree1_invariant(const unordered_map<int, unordered_set<int>>& deg) {
    int degree1_count = 0;
    for (const auto& entry : deg) {
        if (entry.second.size() == 1) {
            ++degree1_count;
        }
    }
    if (degree1_count > deg.size() / 2) { // If more than 50% are degree-1
        cerr << "Warning: Performance bottleneck condition triggered - excessive degree-1 node processing!" << endl;
        abort();
    }
}

void check_frequent_modifications_invariant(int operations, int n) {
    if (operations > 5 * n) { // Arbitrarily setting a threshold of 5 times the number of nodes
        cerr << "Warning: Performance bottleneck condition triggered - frequent modifications in data structure!" << endl;
        abort();
    }
}

void check_iterative_depth_invariant(int levels) {
    if (levels > 10) { // More than 10 levels of processing
        cerr << "Warning: Performance bottleneck condition triggered - deep iterative processing!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, unordered_set<int>> deg;
    int modification_count = 0; // To track the number of modifications

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        deg[a].insert(b);
        deg[b].insert(a);
    }

    check_nested_degree1_invariant(deg); // Check invariant after input

    int levels = 1;
    while (levels <= 11) {
        unordered_map<int, unordered_set<int>> parents;
        for (auto& p : deg) {
            int size = p.second.size();
            if (size == 1) {
                int parent = *p.second.begin();
                parents[parent].insert(p.first);
            }
        }
        if (parents.size() == 1 && parents.begin()->second.size() > 2 &&
            parents.begin()->second.size() + 1 == deg.size()) {
            cout << ((levels == k) ? "Yes" : "No") << endl;
            return 0;
        }
        for (auto& p : parents) {
            int size = p.second.size();
            if (size < 3) {
                cout << "No" << endl;
                return 0;
            }
            for (auto& child : p.second) {
                deg.erase(child);
                deg[p.first].erase(child);
                modification_count += 2; // Two modifications per removal
            }
        }
        ++levels;
        check_iterative_depth_invariant(levels); // Check depth after each level
    }

    check_frequent_modifications_invariant(modification_count, n); // Check modifications after processing

    cout << ((levels == k) ? "Yes" : "No") << endl;
    return 0;
}