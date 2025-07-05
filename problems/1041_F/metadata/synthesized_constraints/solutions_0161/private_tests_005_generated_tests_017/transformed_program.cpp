#include <bits/stdc++.h>
using namespace std;

int a[100100], b[100100];
map<int, int> ma, mb;

// Checker functions
void check_large_size_invariant(int n, int m) {
    if (n > 80000 && m > 80000) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of sensors!" << endl;
        abort();
    }
}

void check_modulus_overlap_invariant(const map<int, int>& ma, const map<int, int>& mb) {
    int overlapCount = 0;
    for (const auto& entry : ma) {
        if (mb.count(entry.first)) {
            overlapCount++;
        }
    }
    if (overlapCount > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - high modulus value overlap!" << endl;
        abort();
    }
}

void check_iteration_depth_invariant(int depth) {
    if (depth > 25) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iteration depth!" << endl;
        abort();
    }
}

void check_map_operation_invariant(const map<int, int>& ma, const map<int, int>& mb, int i) {
    if (ma.size() > 5000 && mb.size() > 5000 && i > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive map operations!" << endl;
        abort();
    }
}

int main() {
    int n, pos;
    cin >> n >> pos;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int m, p;
    cin >> m >> p;
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);

    check_large_size_invariant(n, m); // Check for large size invariant

    if (n == 1 && m == 1 && a[1] == b[1]) {
        puts("2");
        return 0;
    }

    int ans = 0;
    for (int i = 1; i < 31; i++) {
        ma.clear(), mb.clear();
        vector<int> vec;
        int t = (1 << i);

        check_iteration_depth_invariant(i); // Check iteration depth

        for (int i = 1; i <= n; i++) {
            vec.push_back(a[i] % t);
            ma[a[i] % t]++;
        }
        for (int i = 1; i <= m; i++) mb[b[i] % t]++;

        check_modulus_overlap_invariant(ma, mb); // Modulus overlap check

        for (auto p : ma) {
            int r = (p.first + (1 << i - 1)) % t;
            ans = max(ans, mb[r] + p.second);
        }

        check_map_operation_invariant(ma, mb, i); // Map operation check

        for (auto p : mb) {
            int r = (p.first + (1 << i - 1)) % t;
            ans = max(ans, p.second + ma[r]);
        }
    }

    cout << ans << endl;
    return 0;
}