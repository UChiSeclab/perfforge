#include <bits/stdc++.h>
using namespace std;

void check_combination_explosion_invariant(long long w) {
    if (w <= 10) {
        cerr << "Warning: combination_explosion_invariant triggered - small base leading to exponential combinations" << endl;
        abort();
    }
}

void check_search_space_size_invariant(int n) {
    if (n > 20) {
        cerr << "Warning: search_space_size_invariant triggered - large search space size due to many weights" << endl;
        abort();
    }
}

void check_binary_search_performance_invariant(int genSize) {
    if (genSize > 100000) {
        cerr << "Warning: binary_search_performance_invariant triggered - large gen size degrading binary search performance" << endl;
        abort();
    }
}

void check_weight_iteration_overhead_invariant(int n) {
    if (n > 20) {
        cerr << "Warning: weight_iteration_overhead_invariant triggered - excessive iteration over combinations" << endl;
        abort();
    }
}

long long gcd(long long a, long long b) {
    if (!b) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return b / gcd(a, b) * a; }
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
    check_combination_explosion_invariant(w);  // Check for small base causing exponential combinations
    if (w == 2) {
        puts("YES");
        return 0;
    }
    g.push_back(1);
    while (ok(g.back() * w) && g.back() < g.back() * w &&
           (g.back() * w <= 2 * m || g.size() < 22))
        g.push_back(g.back() * w);
    sort(g.begin(), g.end());
    g.resize(unique(g.begin(), g.end()) - g.begin());
    
    int n = g.size();
    check_search_space_size_invariant(n);  // Check for large search space size
    
    for (int i = 0; i < (1 << n); ++i) {
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) sum += g[j];
        }
        if (sum >= 0) gen.push_back(sum);
    }
    check_binary_search_performance_invariant(gen.size());  // Check for large gen size
    
    sort(gen.begin(), gen.end());
    for (int i = 0; i < gen.size(); ++i) {
        if (binary_search(gen.begin() + i + 1, gen.end(), m + gen[i])) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}