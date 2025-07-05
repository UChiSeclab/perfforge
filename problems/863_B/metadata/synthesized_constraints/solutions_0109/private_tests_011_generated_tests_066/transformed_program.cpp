#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_n_invariant(int n) {
    if (n >= 45) {
        cerr << "Warning: Performance bottleneck condition triggered - large n value!" << endl;
        abort();
    }
}

void check_pairing_invariant(int n, const vector<int>& weights) {
    int similar_pairs = 0;
    for (size_t i = 1; i < weights.size(); ++i) {
        if (abs(weights[i] - weights[i - 1]) <= 2) {
            similar_pairs++;
        }
    }
    if (similar_pairs > n) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations for similar weights!" << endl;
        abort();
    }
}

void check_data_structure_invariant(int n) {
    if (n > 40) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient data structure use!" << endl;
        abort();
    }
}

// Main program
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long T = 1;
    for (long long tt = 1; tt <= T; tt++) {
        int n, mn = 1e9;
        cin >> n;
        n *= 2;
        
        // Trigger invariant checks after reading input
        check_large_n_invariant(n / 2);

        vector<int> ls(n);
        for (int &x : ls) cin >> x;
        sort(ls.begin(), ls.end());

        check_pairing_invariant(n / 2, ls);
        check_data_structure_invariant(n / 2);

        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (v != u) {
                    map<int, int> vis;
                    vis[u] = vis[v] = 1;
                    int w = 0, x = 0, sm = 0;
                    while (x < n) {
                        while (vis[w]) w++;
                        while (vis[x] || x == w) x++;
                        if (x < n) sm += ls[x] - ls[w], vis[w] = vis[x] = 1;
                        w++, x++;
                    }
                    mn = min(mn, sm);
                }
            }
        }
        cout << mn;
        cout << '\n';
    }
}