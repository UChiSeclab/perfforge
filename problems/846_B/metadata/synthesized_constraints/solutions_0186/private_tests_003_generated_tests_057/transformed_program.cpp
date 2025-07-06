#include <bits/stdc++.h>
using namespace std;

// Performance-check functions for detecting potential bottlenecks.
void check_nested_loop_invariant(int n, int k) {
    if (n >= 40 && k >= 40) {  // Threshold for significant nested loop impact
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop iterations!" << endl;
        abort();
    }
}

void check_task_vector_size(int taskSize) {
    if (taskSize > 1500) {  // Threshold for large task vector impacting performance
        cerr << "Warning: Performance bottleneck condition triggered - task vector too large!" << endl;
        abort();
    }
}

void check_sort_bottleneck(int taskSize, int sortCount) {
    if (taskSize > 1000 && sortCount > 20) {  // Threshold for sorting overhead
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting of large data!" << endl;
        abort();
    }
}

void check_residual_time_management(int availableTime, int maxTime) {
    if (availableTime < maxTime / 10) {  // Arbitrary threshold for low residual time causing excessive calculations
        cerr << "Warning: Performance bottleneck condition triggered - inefficient use of residual time!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> t(k);
    long long sum = 0;

    for (int i = 0; i < int(k); ++i) {
        cin >> t[i];
        sum += t[i];
    }

    // Check nested loop impact
    check_nested_loop_invariant(n, k);

    int mx = 0;
    int sortCount = 0; // To track the number of sorting operations

    for (int i = 0; i < int(n + 1); ++i) {
        long long tm = sum * i;
        if (tm > m) break;
        int r = m - tm;
        int k0 = k * i + i;
        vector<pair<int, int>> task;

        for (int j = int(i); j < int(n); ++j) {
            for (int p = 0; p < int(k); ++p) {
                task.push_back({t[p], p});
            }
        }

        // Check task vector size
        check_task_vector_size(task.size());

        sort(task.begin(), task.end());
        sortCount++;

        // Check sorting bottleneck
        check_sort_bottleneck(task.size(), sortCount);

        vector<int> pl(k);
        for (int j = 0; j < task.size() && r - task[j].first >= 0; j++) {
            pl[task[j].second]++;
            r -= task[j].first;
            k0++;
        }

        // Check residual time management
        check_residual_time_management(r, m);

        int z = pl[0];
        for (int j = 0; j < int(k); ++j) {
            z = min(z, pl[j]);
        }
        k0 += z;
        mx = max(mx, k0);
    }

    cout << mx << '\n';
}