#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18;
int di[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dj[8] = {1, -1, 0, 0, 1, 1, -1, -1};
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e8 + 7, N = 1e7, M = 2001;
vector<ll> v;

// Check for small weight base
void check_weight_base_invariant(ll w) {
    if (w <= 4) {  // Choosing 4 as the threshold because smaller values increase the search space significantly
        cerr << "Warning: Performance bottleneck: weight base is small!" << endl;
        abort();
    }
}

// Check for excessive recursive calls
void check_recursive_calls_invariant(ll callCount, ll threshold) {
    if (callCount > threshold) {
        cerr << "Warning: Excessive recursive calls!" << endl;
        abort();
    }
}

// Check for unfavorable input combinations
void check_input_combination_invariant(ll m, ll w) {
    if (m > 1e9 && w < 10) {  // Assuming large m with small w causes complexity
        cerr << "Warning: Unfavorable input combination!" << endl;
        abort();
    }
}

void solve(ll m, int i = 0, ll& callCount = *(new ll(0))) {
    // Increment call count
    ++callCount;
    
    // Check recursive calls invariant (choose an arbitrary large threshold for demonstration)
    check_recursive_calls_invariant(callCount, 1e7);

    if (!m) exit(puts("YES"));
    if (i == v.size()) return;
    solve(m, i + 1, callCount);
    solve(m + v[i], i + 1, callCount);
    solve(m - v[i], i + 1, callCount);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll w, m;
    cin >> w >> m;

    // Check for small weight base
    check_weight_base_invariant(w);

    // Check for unfavorable input combinations
    check_input_combination_invariant(m, w);
    
    if (w == 2 || w == 3) return cout << ys << '\n', 0;
    
    v.push_back(1);
    while (v.back() * w <= 9e9 + 99) v.push_back(v.back() * w);
    
    // Initialize call count
    ll callCount = 0;
    solve(m, 0, callCount);
    
    cout << no << '\n';
}