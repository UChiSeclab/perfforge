#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// Checker function implementations
void check_large_m_invariant(long long m) {
    if (m > 500000) {
        cerr << "Warning: Performance bottleneck triggered by large m!" << endl;
        abort();
    }
}

void check_large_n_and_m_invariant(long long n, long long m) {
    if (n + m > 900000) {
        cerr << "Warning: Performance bottleneck triggered by large n + m!" << endl;
        abort();
    }
}

void check_duplicate_handling_invariant(long long m, long long n) {
    if (m > n * 2) {
        cerr << "Warning: Performance bottleneck triggered by high duplicate handling due to large m!" << endl;
        abort();
    }
}

void check_unbalanced_n_and_m_invariant(long long n, long long m) {
    if (m > 3 * n) {
        cerr << "Warning: Performance bottleneck triggered by unbalanced n and m!" << endl;
        abort();
    }
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    t = 1;
    for (long long tc = 0; tc < t; tc++) {
        long long n, m;
        cin >> n >> m;

        // Insert checks after input reading
        check_large_m_invariant(m);
        check_large_n_and_m_invariant(n, m);
        check_duplicate_handling_invariant(m, n);
        check_unbalanced_n_and_m_invariant(n, m);

        long long p = 2;
        unordered_map<long long, long long> mp;
        long long mx = 0;
        for (long long i = 1; i <= n; i++) {
            mx = max(mx, p);
            mp[p]++;
            p += 2;
        }
        p = 3;
        for (long long i = 1; i <= m; i++) {
            mx = max(mx, p);
            mp[p]++;
            p += 3;
        }
        queue<long long> q;
        for (long long i = 2; i <= 2 * (n + m); i++) {
            if (mp[i] == 0) {
                if (i % 2 == 0 || i % 3 == 0) q.push(i);
            }
        }
        for (auto it : mp) {
            if (it.second > 1) {
                mx = max(mx, (long long)q.front());
                mp[q.front()]++;
                mp[it.first]--;
                q.pop();
            }
        }
        cout << mx << "\n";
    }
    return 0;
}