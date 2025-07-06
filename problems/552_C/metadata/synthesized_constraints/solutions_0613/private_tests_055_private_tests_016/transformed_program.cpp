#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

// Performance checkers
void check_recursive_combinatorial_explosion(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - recursive combinatorial explosion!" << endl;
        abort();
    }
}

void check_depth_of_recursion(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void check_inefficient_exploration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient exploration of combinations!" << endl;
        abort();
    }
}

const ll OO = 1e18;
vector<ll> v;

void solve(ll m, int i = 0) {
    static int recursion_counter = 0;
    
    // Check for excessive recursion depth
    check_depth_of_recursion(recursion_counter > 100000); // Arbitrary threshold for recursion depth

    recursion_counter++;
    if (!m) exit(puts("YES"));
    if (i == v.size()) return;
    solve(m, i + 1);
    solve(m + v[i], i + 1);
    solve(m - v[i], i + 1);
    recursion_counter--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll w, m;
    cin >> w >> m;

    // Check for recursive combinatorial explosion scenario
    check_recursive_combinatorial_explosion(w < 10); // Smaller w leads to larger v

    if (w == 2 || w == 3) return cout << "YES\n", 0;

    v.push_back(1);
    while (v.back() * w <= 9e9) v.push_back(v.back() * w);

    // Check for inefficient exploration of combinations
    check_inefficient_exploration(v.size() > 20); // More elements in v lead to more combinations

    solve(m, 0);
    cout << "NO\n";
}