#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trap {
    int l, r, d;
    trap() {}
    trap(int a, int b, int c) {
        l = a; r = b; d = c;
    }
};

// Checkers for performance-characterizing invariants

void check_trap_overlap_invariant(const vector<trap>& Traps, int x) {
    int count = 0;
    for (const auto& tr : Traps) {
        if (tr.d > x) {
            count++;
            if (count > 100) {
                cerr << "Warning: trap_overlap_invariant triggered - too many overlapping traps with high danger level" << endl;
                abort();
            }
        }
    }
}

void check_high_density_traps(const vector<trap>& Traps, int n) {
    vector<int> coverage(n + 2, 0);
    for (const auto& tr : Traps) {
        for (int i = tr.l; i <= tr.r; ++i) {
            coverage[i]++;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (coverage[i] > 10) {
            cerr << "Warning: high_density_traps invariant triggered - high trap coverage at position " << i << endl;
            abort();
        }
    }
}

void check_frequent_path_adjustments(int num_adjustments) {
    if (num_adjustments > 20) {
        cerr << "Warning: frequent_path_adjustments invariant triggered - excessive path recalculations" << endl;
        abort();
    }
}

void solve() {
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vector<int> agility(m);
    vector<trap> Traps(k);
    for (int i = 0; i < m; ++i) {
        cin >> agility[i];
    }
    for (int i = 0; i < k; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        Traps[i] = trap(l, r, d);
    }
    
    sort(agility.begin(), agility.end());

    const int N = 2e5 + 10;
    auto check = [&Traps, &k, &t, &n](int x) -> bool {
        vector<int> R(N, -1);
        for (int i = 0; i < k; ++i) {
            if (Traps[i].d > x) {
                R[Traps[i].l] = max(R[Traps[i].l], Traps[i].r);
            }
        }

        ll total = 0;
        int i = 0;
        int num_adjustments = 0; // Track adjustments
        while (i < n + 1) {
            int j = i;
            int target = R[j];
            if (target == -1) {
                i++;
                total++;
                continue;
            }
            while (j < target) {
                j++;
                target = max(target, R[j]);
                num_adjustments++; // Increment on each path adjustment
            }
            total += 1LL * (j - i + 1) * 2 + (j - i);
            if (i == j) {
                i++;
                total++;
                continue;
            }
            i = j;
        }
        
        // Check for frequent path adjustments
        check_frequent_path_adjustments(num_adjustments);
        
        return total <= (ll)t;
    };

    // Check high density traps before binary search
    check_high_density_traps(Traps, n);

    int ans = 0;
    int left = 0;
    int right = m - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check trap overlap invariant during binary search
        check_trap_overlap_invariant(Traps, agility[mid]);
        
        if (check(agility[mid])) {
            ans = m - 1 - mid + 1;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}