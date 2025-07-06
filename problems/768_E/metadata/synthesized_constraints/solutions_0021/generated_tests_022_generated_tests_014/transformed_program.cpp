#include <bits/stdc++.h>
using namespace std;

// Map to store computed Grundy numbers
map<pair<int, long long>, int> gru;

// Checker function for large pile sizes
void check_recursive_depth_invariant(int pile_size) {
    if (pile_size > 50) { // Assuming pile_size as a threshold for exploring large states
        cerr << "Warning: Performance bottleneck due to deep recursion or large state space!" << endl;
        abort();
    }
}

// Checker function for map size indicating ineffective caching
void check_caching_invariant(int map_size) {
    if (map_size > 100000) { // Assuming a large map size leads to ineffective caching
        cerr << "Warning: Performance bottleneck due to insufficient caching of states!" << endl;
        abort();
    }
}

// Checker function for high branching factor
void check_branching_factor_invariant(int u) {
    if (u > 50) { // Assuming high branching factor when u is large
        cerr << "Warning: Performance bottleneck due to high branching factor in recursion!" << endl;
        abort();
    }
}

int grundy(int u, long long w) {
    if (u == 0) return 0;
    if (gru.find(make_pair(u, w)) != gru.end()) return gru[make_pair(u, w)];

    // Checkers integrated before processing
    check_branching_factor_invariant(u);
    
    set<int> yo;
    for (int i = 1; i <= u; i++) {
        if ((w & (1 << i)) == 0) {
            yo.insert(grundy(u - i, (w | (1 << i))));
        }
    }
    set<int>::iterator it;
    int ans = 0;
    for (it = yo.begin(); it != yo.end(); it++) {
        if (ans != *it) {
            break;
        }
        ans++;
    }
    // Check caching invariant after inserting new states
    check_caching_invariant(gru.size());
    return gru[make_pair(u, w)] = ans;
}

int main() {
    int ans = 0;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        // Check recursive depth invariant before calling grundy
        check_recursive_depth_invariant(x);

        ans ^= grundy(x, 0);
    }
    if (ans == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}