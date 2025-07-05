#include <bits/stdc++.h>
using namespace std;

// Phase 3: Checker functions
void check_large_window(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large sliding window." << endl;
        abort();
    }
}

void check_high_diversity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high diversity of TV shows." << endl;
        abort();
    }
}

void check_frequent_changes(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent episode changes." << endl;
        abort();
    }
}

void check_test_case_limit(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - too many test cases." << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    
    // Check for too many test cases given the constraints
    check_test_case_limit(t > 100);

    for (int l = 0; l < t; l++) {
        int n, k, d;
        cin >> n >> k >> d;

        // Check for large sliding window compared to n
        check_large_window(d > n / 2);

        // Check for high diversity of TV shows
        check_high_diversity(k > d);

        int *a = new int[n];
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]] = 0;
        }
        
        deque<int> q;
        int j = 0;
        for (int i = 0; i < d; i++) {
            if (m[a[i]] == 0) {
                q.push_back(a[i]);
                m[a[i]] = 1;
            } else {
                m[a[i]] = m[a[i]] + 1;
            }
            j = i;
        }
        int ans = q.size();
        int start = 0;
        int end1 = d;
        for (int i = end1; i < (n); i++) {
            m[a[start]] = m[a[start]] - 1;
            if (m[a[start]] == 0) {
                q.pop_front();
            }
            if (m[a[i]] == 0) {
                q.push_back(a[i]);
                m[a[i]] = 1;
            } else {
                m[a[i]] = m[a[i]] + 1;
            }

            // Check for frequent episode changes
            check_frequent_changes(q.size() > d / 2);

            int k = q.size();
            if (ans > k) {
                ans = k;
            }
            start = start + 1;
        }
        cout << ans << endl;
        delete[] a; // Clean up the dynamically allocated array
    }
}