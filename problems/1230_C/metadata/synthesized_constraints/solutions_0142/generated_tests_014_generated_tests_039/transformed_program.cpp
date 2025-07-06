#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long sz = 1e5 + 20;
const long long N = 7;
vector<pair<long long, long long> > edges;
long long c[N];

// Checker functions
void check_permutation_exhaustion_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to permutation exhaustion!" << endl;
        abort();
    }
}

void check_recursive_edge_processing_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to excessive recursive edge processing!" << endl;
        abort();
    }
}

void check_repeated_state_transition_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to repeated state transitions in recursion!" << endl;
        abort();
    }
}

long long rec() {
    set<pair<long long, long long> > s;
    for (auto edge : edges) {
        long long u = edge.first, v = edge.second, cu = c[u - 1], cv = c[v - 1];
        if (cu > cv) swap(cu, cv);
        s.insert(make_pair(cu, cv));
    }
    return s.size();
}

void solve() {
    long long n, m;
    cin >> n >> m;

    // Check for potential permutation exhaustion
    check_permutation_exhaustion_invariant(n == 7);

    long long u, v;
    for (long long i = 0; i < m; i++) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        edges.push_back(make_pair(u, v));
    }

    if (n <= 6) {
        cout << m << endl;
    } else {
        long long ans = 0;

        // Check for excessive recursive edge processing and state transitions
        check_recursive_edge_processing_invariant(m > 15);
        check_repeated_state_transition_invariant(edges.size() > 15);

        for (long long extra = 0; extra < N - 1; extra++) {
            for (long long i = 0; i < N - 1; i++) c[i] = i;
            c[6] = extra;
            do {
                ans = max(rec(), ans);
            } while (next_permutation(c, c + N));
        }
        cout << ans << endl;
    }
    return;
}

int32_t main() {
    clock_t st = clock();
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    while (t--) {
        solve();
    }
    clog << (long double)((clock() - st) / CLOCKS_PER_SEC) << endl;
    return 0;
}