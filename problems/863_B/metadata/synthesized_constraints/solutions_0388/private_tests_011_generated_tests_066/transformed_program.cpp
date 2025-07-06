#include <bits/stdc++.h>
using namespace std;

// Checkers for Performance Invariants
void check_pair_loop_invariant(int n) {
    int max_combinations = (n * 2) * (n * 2 - 1) / 2;
    if (max_combinations > 2500) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive pair combinations" << endl;
        abort();
    }
}

void check_multiset_processing_invariant(int n) {
    int operations_count = (n * (n - 1)) / 2;
    if (operations_count > 1250) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive multiset operations" << endl;
        abort();
    }
}

void check_combination_invariant(int n) {
    int estimated_operations = (n * 2) * (n * 2 - 1) * (n - 1);
    if (estimated_operations > 125000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive combinations and calculations" << endl;
        abort();
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    // Placing the first check right after reading input
    check_pair_loop_invariant(n);
    check_multiset_processing_invariant(n);
    check_combination_invariant(n);
    
    vector<int> w(n * 2);
    for (auto& x : w) cin >> x;
    sort(w.begin(), w.end());
    int ans = INT_MAX;
    for (int i = 0; i < n * 2; ++i) {
        for (int j = i + 1; j < n * 2; ++j) {
            multiset<int> unpaired(w.begin(), w.end());
            unpaired.erase(unpaired.find(w[i]));
            unpaired.erase(unpaired.find(w[j]));
            int cur = 0;
            while (!unpaired.empty()) {
                cur -= *unpaired.begin();
                unpaired.erase(unpaired.begin());
                cur += *unpaired.begin();
                unpaired.erase(unpaired.begin());
            }
            ans = min(ans, cur);
        }
    }
    cout << ans;
}