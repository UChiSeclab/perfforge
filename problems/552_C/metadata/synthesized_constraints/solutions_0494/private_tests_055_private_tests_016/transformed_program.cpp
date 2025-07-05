#include <bits/stdc++.h>
using namespace std;

// Performance-checking functions
void check_small_w_invariant(long long w, long long m) {
    if (w < 10) { // Threshold for `w` illustrating potential small base impact
        cerr << "Warning: Performance bottleneck condition triggered - Small base w causing exhaustive generation." << endl;
        abort();
    }
}

void check_large_g_invariant(const vector<long long>& g) {
    if (g.size() > 20) { // Threshold indicating large number of generated weights
        cerr << "Warning: Performance bottleneck condition triggered - Large number of generated weights." << endl;
        abort();
    }
}

void check_large_gen_invariant(const vector<long long>& gen) {
    if (gen.size() > 1000000) { // Threshold for extensive search space
        cerr << "Warning: Performance bottleneck condition triggered - Large search space for combinations." << endl;
        abort();
    }
}

// Original program
long long w, m;
vector<long long> g;
vector<long long> gen;

bool ok(long long x) {
    if (x < 1) return 0;
    while (x % w == 0) x /= w;
    return x == 1;
}

int main() {
    cin >> w >> m;
    
    // Check for small `w` invariant
    check_small_w_invariant(w, m);

    if (w == 2) {
        puts("YES");
        return 0;
    }
    
    g.push_back(1);
    while (ok(g.back() * w) && g.back() < g.back() * w &&
           (g.back() * w <= 2 * m || g.size() < 22))
        g.push_back(g.back() * w);
    
    // Check for large `g` invariant
    check_large_g_invariant(g);

    sort(g.begin(), g.end());
    g.resize(unique(g.begin(), g.end()) - g.begin());
    int n = g.size();
    for (int i = 0; i < (1 << n); ++i) {
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) sum += g[j];
        }
        if (sum >= 0) gen.push_back(sum);
    }

    // Check for large `gen` invariant
    check_large_gen_invariant(gen);

    sort(gen.begin(), gen.end());
    for (int i = 0; i < gen.size(); ++i) {
        if (binary_search(gen.begin(), gen.end(), m + gen[i])) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}