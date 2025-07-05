#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_no_customers_invariant(int n) {
    if (n == 0) {
        cerr << "Warning: Performance bottleneck triggered - no regular customers, full day iteration." << endl;
        abort();
    }
}

void check_extensive_free_time_invariant(int n, int L, const vector<pair<int, int>>& a) {
    if (n > 0) {
        int totalServiceTime = 0;
        for (const auto& customer : a) {
            totalServiceTime += customer.second;
        }
        if (totalServiceTime < L / 2) {
            cerr << "Warning: Performance bottleneck triggered - extensive free time relative to L." << endl;
            abort();
        }
    }
}

int main() {
    int n, L, s;
    cin >> n >> L >> s;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int ini, d;
        cin >> ini >> d;
        a[i] = make_pair(ini, d);
    }

    // Apply invariant checks after reading input
    check_no_customers_invariant(n);
    check_extensive_free_time_invariant(n, L, a);

    int i = 0, k = 0, last = 0;
    for (int j = 0; j < L;) {
        if (i < a.size() && a[i].first == j) {
            j += a[i].second;
            i++;
            last = j;
        } else {
            j++;
            if (j - last == s) {
                last = j;
                k++;
            }
        }
    }
    cout << k;
}