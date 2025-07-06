#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_tide_depth_invariant(const vector<int>& depths, int k, int l) {
    for (int i = 0; i < depths.size(); ++i) {
        int maxTideEffect = k;
        if (depths[i] + maxTideEffect > l) {
            cerr << "Warning: Tide and depth interaction invariant triggered - depth with tide exceeds limit" << endl;
            abort();
        }
    }
}

void check_queue_growth_invariant(int queueSize, int threshold = 1000) {
    if (queueSize > threshold) {
        cerr << "Warning: Queue growth invariant triggered - queue size too large" << endl;
        abort();
    }
}

void check_transition_threshold_invariant(int k, int l, const vector<int>& depths) {
    for (int i = 0; i < depths.size(); ++i) {
        int criticalThreshold = l - k;
        if (depths[i] > criticalThreshold) {
            cerr << "Warning: Transition threshold invariant triggered - depths near critical threshold" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TC;
    cin >> TC;
    while (TC--) {
        int n, k, l;
        cin >> n >> k >> l;
        
        vector<int> depths(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> depths[i];
        }

        // Inserted invariant checks
        check_tide_depth_invariant(depths, k, l);
        check_transition_threshold_invariant(k, l, depths);

        int arr[n + 1][k * 2];
        memset(arr, 0, sizeof(arr));
        int p[k * 2];
        memset(p, 0, sizeof(p));
        for (int i = 0; i < k * 2; i++) {
            if (i <= k)
                p[i] = i;
            else
                p[i] = k + k - i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < k * 2; j++) {
                arr[i][j] = depths[i] + p[j];
            }
        }
        bool v[n + 1][k * 2];
        memset(v, 0, sizeof(v));
        queue<pair<int, int>> q;
        for (int i = 0; i < k * 2; i++) {
            q.push({0, i});
            v[0][i] = true;
        }
        bool flag = false;
        while (!q.empty()) {
            int pos = q.front().first;
            int t = q.front().second;
            q.pop();

            // Check queue size to avoid excessive growth
            check_queue_growth_invariant(q.size());

            if (pos == n) {
                flag = true;
                break;
            }
            int npos = pos + 1;
            int nt = (t + 1) % (k * 2);
            if (!v[npos][nt] && (arr[npos][nt] <= l))
                q.push({npos, nt}), v[npos][nt] = true;
            if (!v[pos][nt] && (arr[pos][nt] <= l))
                q.push({pos, nt}), v[pos][nt] = true;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "No\n";
    }
}