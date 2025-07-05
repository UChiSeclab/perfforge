#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

void check_modulo_classes_invariant(int uniqueModuloClasses, int threshold) {
    if (uniqueModuloClasses > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many unique modulo classes!" << endl;
        abort();
    }
}

void check_dp_updates_invariant(int dpUpdates, int maxUpdates) {
    if (dpUpdates > maxUpdates) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive dynamic programming updates!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int operationsCount, int maxOperations) {
    if (operationsCount > maxOperations) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive operations in nested loops!" << endl;
        abort();
    }
}

int main() {
    int yyyy;
    int n;
    scanf(" %d %d", &n, &yyyy);
    vector<int> a(n);
    for (int(i) = 0; (i) < (int)(n); ++(i)) scanf(" %d", &a[i]);
    int m;
    scanf(" %d %d", &m, &yyyy);
    vector<int> b(m);
    for (int(i) = 0; (i) < (int)(m); ++(i)) scanf(" %d", &b[i]);

    vector<pi> v;
    for (int(i) = 0; (i) < (int)(n); ++(i)) v.push_back({a[i], i});
    for (int(i) = 0; (i) < (int)(m); ++(i)) v.push_back({b[i], n + i});
    sort((v).begin(), (v).end());
    int V = v.size();
    unordered_map<int, int> IDA, IDB;
    for (int(i) = 0; (i) < (int)(n); ++(i)) IDA[a[i]] = i;
    for (int(i) = 0; (i) < (int)(m); ++(i)) IDB[b[i]] = n + i;
    int ans = 2;

    int maxModuloClasses = 1000; // Example threshold for modulo classes
    int maxDpUpdates = 50000; // Example threshold for DP updates
    int maxOperations = 100000; // Example threshold for nested loop operations

    for (int d = 1; d < (1 << 30); d *= 2) {
        int mod = 2 * d;
        unordered_map<int, int> mod2id;
        int ct = 0;

        for (int(i) = 0; (i) < (int)(n); ++(i))
            if (!mod2id.count(a[i] % mod)) {
                mod2id[a[i] % mod] = ct;
                ++ct;
            }
        for (int(i) = 0; (i) < (int)(m); ++(i))
            if (!mod2id.count(b[i] % mod)) {
                mod2id[b[i] % mod] = ct;
                ++ct;
            }

        // Check for excessive unique modulo classes
        check_modulo_classes_invariant(ct, maxModuloClasses);

        vector<vector<int>> aa(ct), bb(ct);
        for (int(i) = 0; (i) < (int)(n); ++(i))
            aa[mod2id[a[i] % mod]].push_back(a[i]);
        for (int(i) = 0; (i) < (int)(m); ++(i))
            bb[mod2id[b[i] % mod]].push_back(b[i]);

        vector<int> dp(V, 1);
        int dpUpdates = 0;
        int operationsCount = 0;
        for (int(i) = 0; (i) < (int)(V); ++(i)) {
            operationsCount++;
            int idx = v[i].second;
            if (idx < n) {
                int key = a[idx] % mod;
                key = mod2id[key];
                auto itr = upper_bound((aa[key]).begin(), (aa[key]).end(), a[idx]);
                if (itr != aa[key].end()) {
                    assert(IDA.count(*itr));
                    int nidx = IDA[*itr];
                    dp[nidx] = max(dp[nidx], dp[idx] + 1);
                    dpUpdates++;
                }
                key = (a[idx] + d) % mod;
                if (!mod2id.count(key)) continue;
                key = mod2id[key];
                itr = lower_bound((bb[key]).begin(), (bb[key]).end(), a[idx] + d);
                if (itr != bb[key].end()) {
                    assert(IDB.count(*itr));
                    int nidx = IDB[*itr];
                    dp[nidx] = max(dp[nidx], dp[idx] + 1);
                    dpUpdates++;
                }
            } else {
                int key = b[idx - n] % mod;
                key = mod2id[key];
                auto itr = upper_bound((bb[key]).begin(), (bb[key]).end(), b[idx - n]);
                if (itr != bb[key].end()) {
                    assert(IDB.count(*itr));
                    int nidx = IDB[*itr];
                    dp[nidx] = max(dp[nidx], dp[idx] + 1);
                    dpUpdates++;
                }
                key = (b[idx - n] + d) % mod;
                if (!mod2id.count(key)) continue;
                key = mod2id[key];
                itr = lower_bound((aa[key]).begin(), (aa[key]).end(), b[idx - n] + d);
                if (itr != aa[key].end()) {
                    assert(IDA.count(*itr));
                    int nidx = IDA[*itr];
                    dp[nidx] = max(dp[nidx], dp[idx] + 1);
                    dpUpdates++;
                }
            }
        }

        // Check for excessive DP updates
        check_dp_updates_invariant(dpUpdates, maxDpUpdates);
        // Check for excessive operations in nested loops
        check_nested_loop_invariant(operationsCount, maxOperations);

        for (int(i) = 0; (i) < (int)(V); ++(i)) ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}