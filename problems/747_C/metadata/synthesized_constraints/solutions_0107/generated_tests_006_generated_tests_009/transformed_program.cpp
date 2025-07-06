#include <bits/stdc++.h>
using namespace std;

struct task {
    int t, k, d;
    task() {}
    task(int a, int b, int c) {
        t = a;
        k = b;
        d = c;
    }
};

// Checkers for performance bottleneck conditions
void check_server_allocation_invariant(int n, int k) {
    if (n > 50 && k > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - High server allocation!" << endl;
        abort();
    }
}

void check_long_duration_invariant(int di) {
    if (di > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - Task duration too long!" << endl;
        abort();
    }
}

void check_full_utilization_invariant(int free, int k) {
    if (free < k) {
        cerr << "Warning: Performance bottleneck condition triggered - Frequent full server utilization!" << endl;
        abort();
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<task> v(q);
    int a, b, c;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        v[i] = task(a, b, c);
    }
    reverse(v.begin(), v.end());
    vector<int> servers(n, 0);
    for (int i = 1; i <= 1e6 + 3333; ++i) {
        if (v.size()) {
            task cur = v.back();
            a = cur.t;
            b = cur.k;
            c = cur.d;
            
            // Check server allocation invariant
            check_server_allocation_invariant(n, b);
            // Check long duration invariant
            check_long_duration_invariant(c);

            if (a == i) {
                int free = 0;
                for (int j = 0; j < servers.size(); ++j) {
                    if (!servers[j]) free++;
                }
                
                // Check full utilization invariant
                check_full_utilization_invariant(free, b);

                int tot = b;
                int sum = 0;
                if (free >= b) {
                    for (int j = 0; j < servers.size() && tot > 0; ++j) {
                        if (servers[j] == 0) {
                            servers[j] = c;
                            sum += j + 1;
                            tot--;
                        }
                    }
                    cout << sum << '\n';
                } else {
                    cout << -1 << '\n';
                }
                v.pop_back();
            }
        }
        for (int j = 0; j < servers.size(); ++j) {
            if (servers[j] > 0) servers[j]--;
        }
    }
    return 0;
}