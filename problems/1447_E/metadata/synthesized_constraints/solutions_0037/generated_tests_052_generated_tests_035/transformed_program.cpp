#include <bits/stdc++.h>
using namespace std;

// Checkers for invariants
void check_bit_diversity_invariant(const set<int>& s, int threshold) {
    set<int> unique_high_bits;
    for (int x : s) {
        unique_high_bits.insert(x >> 28); // check the top 4 bits as a proxy for "high bit diversity"
    }
    if (unique_high_bits.size() > threshold) {
        cerr << "Warning: bit_diversity_invariant triggered - high bit diversity" << endl;
        abort();
    }
}

void check_partition_size_invariant(size_t size, size_t threshold) {
    if (size > threshold) {
        cerr << "Warning: partition_size_invariant triggered - large set size with non-trivial partitions" << endl;
        abort();
    }
}

void check_xor_partition_invariant(size_t s0_size, size_t s1_size, size_t threshold) {
    if (s0_size > threshold && s1_size > threshold) {
        cerr << "Warning: xor_partition_invariant triggered - complex XOR partitioning" << endl;
        abort();
    }
}

// Recursive function to determine the minimum number of removals
int f(set<int>& s, int j) {
    if (j < 0) return 0;
    if (s.size() == 0) return 0;

    // Invariant check for large set size
    check_partition_size_invariant(s.size(), 200); // Use a threshold based on problem constraints

    set<int> s0;
    set<int> s1;
    long long mask = ((long long)1 << j);
    for (auto& x : s) {
        if ((x & mask) == 0) {
            s0.insert(x);
        } else {
            s1.insert(x);
        }
    }
    
    // Invariant check for XOR partition
    check_xor_partition_invariant(s0.size(), s1.size(), 10); // Arbitrary threshold for demonstration

    if (s0.size() <= 1) {
        return f(s1, j - 1);
    } else if (s1.size() <= 1) {
        return f(s0, j - 1);
    } else {
        return min(s0.size() - 1 + f(s1, j - 1), s1.size() - 1 + f(s0, j - 1));
    }
}

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    // Invariant check for bit diversity
    check_bit_diversity_invariant(s, 15); // Threshold based on expected high bit diversity

    cout << f(s, 35) << '\n';
}

int32_t main(int32_t argc, char** argv) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
}