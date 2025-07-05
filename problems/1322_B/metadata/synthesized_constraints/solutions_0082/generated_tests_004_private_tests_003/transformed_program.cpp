#include <bits/stdc++.h>
using namespace std;

// Checker function for high frequency of repeated range queries
void check_query_invariant(int n) {
    if (n > 90) { // Assuming 90 is close to the upper limit of 100 causing significant slowdown
        cerr << "Warning: query_invariant triggered - high frequency of repeated range queries" << endl;
        abort();
    }
}

// Checker function for nested loop intensity
void check_loop_invariant(int n) {
    if (n > 90) { // Check for large n indicating intense nested looping
        cerr << "Warning: loop_invariant triggered - large number of iterations in nested loop" << endl;
        abort();
    }
}

// Checker function for bit-level computation overhead
void check_bit_computation_invariant(int n) {
    if (n > 90) { // Check for high n causing intensive bit-level operations
        cerr << "Warning: bit_computation_invariant triggered - extensive bit-level operations" << endl;
        abort();
    }
}

int get(vector<int>& v, int x) {
    auto it = upper_bound(v.begin(), v.end(), x);
    return it - v.begin();
}

int cnt(vector<int>& v, int l, int r) { return get(v, r - 1) - get(v, l - 1); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    // Insert checks after reading input
    check_query_invariant(n);
    check_loop_invariant(n);
    check_bit_computation_invariant(n);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        vector<int> v;
        for (int x : a) v.push_back(x % (1 << (i + 1)));
        sort(v.begin(), v.end());
        
        long long tmp = 0;
        for (int x : v) {
            tmp += cnt(v, (1 << i) - x, (2 << i) - x);
            tmp += cnt(v, (3 << i) - x, (4 << i) - x);
            if ((2 * x) & (1 << i)) {
                tmp--;
            }
        }
        
        tmp /= 2;
        if (tmp & 1) ans ^= 1 << i;
    }
    cout << ans;
    return 0;
}