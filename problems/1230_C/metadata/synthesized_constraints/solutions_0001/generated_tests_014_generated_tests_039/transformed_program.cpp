#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long sz = 1e5 + 20;
const long long N = 7;
vector<pair<long long, long long> > edges;
long long c[N];
vector<long long> g[N];

// Checker functions
void check_dense_graph_invariant(int n, int m) {
    if (m > (n * (n - 1)) / 2 * 0.8) {
        cerr << "Warning: Performance bottleneck condition triggered due to dense graph!" << endl;
        abort();
    }
}

void check_complex_permutation_invariant(int n, int permutationCount) {
    if (permutationCount > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive permutations!" << endl;
        abort();
    }
}

void check_recursive_permutation_invariant(int n, int m) {
    if (n == 7 && m > 15) {
        cerr << "Warning: Performance bottleneck condition triggered due to complex recursive permutations!" << endl;
        abort();
    }
}

long long rec() {
    set<pair<long long, long long> > s;
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
    
    // Check dense graph invariant
    check_dense_graph_invariant(n, m);

    long long u, v;
    for (long long i = 0; i < m; i++) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        g[v].push_back(u), g[u].push_back(v);
    }

    if (n <= 6)
        cout << m << endl;
    else {
        long long ans = 0;
        int permutationCount = 0; // Counter for permutations
        for (long long extra = 0; extra < N - 1; extra++) {
            for (long long i = 0; i < N - 1; i++) c[i] = i;
            c[6] = extra;
            sort(c, c + N);
            do {
                ans = max(rec(), ans);
                permutationCount++; // Count each permutation
            } while (next_permutation(c, c + N));
        }

        // Check complex permutation invariant
        check_complex_permutation_invariant(n, permutationCount);
        
        // Check recursive permutation invariant
        check_recursive_permutation_invariant(n, m);

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