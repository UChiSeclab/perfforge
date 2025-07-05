#include <bits/stdc++.h>
using namespace std;

// Invariant checker functions
void check_loop_iteration_growth(long long n) {
    if (n >= 1000000) {  // Example threshold for large n
        cerr << "Warning: Performance bottleneck condition triggered due to high loop iterations!" << endl;
        abort();
    }
}

void check_map_vector_operations(long long n) {
    if (n >= 1000000) {  // Example threshold for large n
        cerr << "Warning: Performance bottleneck condition triggered due to extensive map/vector operations!" << endl;
        abort();
    }
}

void check_large_output_processing(size_t ansSize) {
    if (ansSize > 10000) {  // Example threshold for large output size
        cerr << "Warning: Performance bottleneck condition triggered due to large output size!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        long long n, i;
        cin >> n;

        // Check for loop iteration and map/vector operations
        check_loop_iteration_growth(n);
        check_map_vector_operations(n);

        vector<long long> ans;
        ans.push_back(0);
        map<long long, long long> m;
        for (i = 1; i * i <= n; i++) {
            long long j = n / i;
            if (m[j] == 0) {
                m[j]++;
                ans.push_back(j);
            }
            j = n / j;
            if (m[j] == 0) {
                m[j]++;
                ans.push_back(j);
            }
        }

        // Check large output size before sorting or printing
        check_large_output_processing(ans.size());

        cout << ans.size() << '\n';
        sort(ans.begin(), ans.end());
        for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}