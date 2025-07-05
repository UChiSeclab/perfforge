#include <bits/stdc++.h>
using namespace std;

// Invariant checkers
void check_large_input_and_divisions(vector<int>& v) {
    for (int x : v) {
        if (x > 100000) {
            cerr << "Warning: Large input value causing excessive divisions!" << endl;
            abort();
        }
    }
}

void check_res_size_invariant(vector<int>& res) {
    if (res.size() > 500) {
        cerr << "Warning: res vector is too large, causing performance issues!" << endl;
        abort();
    }
}

void check_nested_iterations(int n, int resSize) {
    if (n * resSize > 2000) {
        cerr << "Warning: Too many nested iterations causing slowdown!" << endl;
        abort();
    }
}

void check_sorting_operations(vector<int>& cnt) {
    if (cnt.size() > 20) {
        cerr << "Warning: Excessive sorting operations detected!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> res;
    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Check for large input values
    check_large_input_and_divisions(v);

    for (int i = 0; i < n; i++) {
        int x = v[i];
        while (x > 0) {
            res.push_back(x);
            x /= 2;
        }
    }

    // Check for large res size
    check_res_size_invariant(res);
    // Check nested iteration potential problem
    check_nested_iterations(n, res.size());

    for (auto x : res) {
        vector<int> cnt;
        for (int i = 0; i < n; i++) {
            int r = 0;
            int cur = 0;
            int p = v[i];
            while (p > x) {
                p /= 2;
                cur++;
            }
            if (p == x) cnt.push_back(cur);
        }

        // Check for excessive sorting operations
        check_sorting_operations(cnt);

        if (cnt.size() >= k) {
            sort(cnt.begin(), cnt.end());
            ans = min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0));
        }
    }

    cout << ans << "\n";
}