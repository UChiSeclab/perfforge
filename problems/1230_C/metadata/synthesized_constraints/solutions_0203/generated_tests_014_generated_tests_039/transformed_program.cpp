#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long sz = 1e5 + 20;
const long long N = 7;
vector<pair<long long, long long>> edges;
long long c[N];
vector<long long> g[N];

// Checker for graph density-related performance bottleneck
void check_graph_density_invariant(int n, int m) {
    // If m is large compared to n (close to a complete graph), this may slow down
    if (m > n * (n - 1) / 4) { // Example threshold: half of the max edges possible
        cerr << "Warning: Performance bottleneck condition triggered due to graph density!" << endl;
        abort();
    }
}

// Checker for permutation-related bottleneck
void check_permutation_invariant(int n) {
    // If the number of nodes n is high, permutations might be too extensive
    if (n > 5) { // Considering factorial growth, n > 5 leads to excessive permutations
        cerr << "Warning: Performance bottleneck condition triggered due to excessive permutations!" << endl;
        abort();
    }
}

// Checker for node connectivity-related performance bottleneck
void check_node_connectivity_invariant(const vector<long long> g[], int n) {
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > n / 2) { // Example threshold: high connectivity relative to the node count
            cerr << "Warning: Performance bottleneck condition triggered due to high node connectivity!" << endl;
            abort();
        }
    }
}

long long rec() {
    set<pair<long long, long long>> s;
    for (long long i = 1; i < N; i++) {
        for (long long node : g[i]) {
            long long cu = c[i - 1], cv = c[node - 1];
            if (cu > cv) swap(cu, cv);
            s.insert(make_pair(cu, cv));
        }
    }
    return s.size();
}

void solve() {
    long long n, m;
    cin >> n >> m;

    // Insert checker for graph density
    check_graph_density_invariant(n, m);

    long long u, v;
    for (long long i = 0; i < m; i++) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        g[v].push_back(u), g[u].push_back(v);
    }

    // Insert checker for node connectivity
    check_node_connectivity_invariant(g, n);

    if (n <= 6)
        cout << m << endl;
    else {
        long long ans = 0;
        
        // Insert checker for permutation-related bottleneck
        check_permutation_invariant(n);

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    while (t--) {
        solve();
    }
    clog << (long double)((clock() - st) / CLOCKS_PER_SEC) << endl;
    return 0;
}