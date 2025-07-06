#include <bits/stdc++.h>
using namespace std;

// Check for large gaps between starting positions and nearest prizes
void check_large_gap_invariant(const deque<long long>& dq) {
    if (!dq.empty() && (dq.front() > 50 || 1e6 - dq.back() > 50)) {
        cerr << "Warning: Performance bottleneck condition triggered - large gap between starting positions and nearest prizes!" << endl;
        abort();
    }
}

// Check for symmetrical and distant placement of prizes
void check_symmetrical_placement_invariant(const deque<long long>& dq) {
    if (!dq.empty() && ((dq.front() > 50) && (1e6 - dq.back() > 50))) {
        cerr << "Warning: Performance bottleneck condition triggered - symmetrical and distant placement of prizes!" << endl;
        abort();
    }
}

// Check for prizes clustered in the middle
void check_clustering_invariant(const deque<long long>& dq) {
    if (!dq.empty() && (dq.front() > 500000 && dq.back() < 600000)) {
        cerr << "Warning: Performance bottleneck condition triggered - prizes clustered in the middle!" << endl;
        abort();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n;
    cin >> n;
    deque<long long> dq;
    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        dq.push_back(x);
    }

    // Insert checks here, after populating the deque and before the main loop
    check_large_gap_invariant(dq);
    check_symmetrical_placement_invariant(dq);
    check_clustering_invariant(dq);

    for (long long i = 1; i <= 2e6; i++) {
        while ((long long)dq.size()) {
            if (dq.front() - 1 <= i) {
                dq.pop_front();
            } else
                break;
        }
        while ((long long)dq.size()) {
            if (1e6 - dq.back() <= i) {
                dq.pop_back();
            } else
                break;
        }
        if (dq.empty()) {
            cout << i << '\n';
            break;
        }
    }
}