#include <bits/stdc++.h>
int mod = 1000000007;
const double pi = 3.141592653689793238460;
const int inf = 0x3f3f3f3f;
using namespace std;

// Checker function for transformations
void check_transformation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - high number of transformations detected!" << endl;
        abort();
    }
}

// Checker function for `pos` vector size
void check_pos_size_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - `pos` vector size is too large!" << endl;
        abort();
    }
}

// Checker function for sorting and accumulation
void check_sort_accumulate_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - excessive sorting and accumulation!" << endl;
        abort();
    }
}

// Checker function for nesting and branching
void check_nesting_branching_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - deep nesting and high branching factor!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    int a[10005];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 0) {
            pos.push_back(x);
            x /= 2;
        }
    }
    
    // Check for large `pos` size
    check_pos_size_invariant(pos.size() > 500);  // Example threshold, adjust as needed

    int ans = inf;
    for (auto x : pos) {
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int y = a[i];
            while (y > x) {
                y /= 2;
                cnt++;
            }
            if (y == x) {
                cur.push_back(cnt);
            }
        }
        
        // Check for excessive sorting and accumulation
        check_sort_accumulate_invariant(cur.size() >= n);  // Example condition, adjust as needed
        
        if (cur.size() < k) continue;
        sort(cur.begin(), cur.end());
        ans = min(ans, accumulate(cur.begin(), cur.begin() + k, 0));
    }
    
    cout << ans << endl;
}