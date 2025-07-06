#include <bits/stdc++.h>
using namespace std;

// Invariant checker functions
void check_large_ni_invariant(int ni) {
    if (ni > 500000) {  // Threshold chosen for demonstration; adjust based on actual analysis
        cerr << "Warning: Performance bottleneck condition triggered due to large n_i!" << endl;
        abort();
    }
}

void check_approaching_upper_bound(int ni) {
    if (ni > 900000) {  // Threshold chosen for demonstration; adjust based on actual analysis
        cerr << "Warning: Performance bottleneck due to n_i approaching upper bound!" << endl;
        abort();
    }
}

void check_many_tests_large_values(int t, int ni) {
    if (t > 500000 && ni > 500000) {  // Thresholds chosen for demonstration; adjust based on actual analysis
        cerr << "Warning: Performance bottleneck due to many tests with large n_i!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<pair<int, int>> a(t);
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        a[i] = make_pair(x, i);

        // Check invariants after reading each input
        check_large_ni_invariant(x);
        check_approaching_upper_bound(x);
        check_many_tests_large_values(t, x);
    }
    sort(a.begin(), a.end());
    queue<int> next;
    int MAXN = 1000005;
    vector<bool> isprime(MAXN, 1);
    int last = 1;
    int ans = 1;
    vector<int> rta(t);
    for (int T = 0; T < t; T++) {
        if (last >= a[T].first)
            rta[a[T].second] = ans;
        else {
            while (last < a[T].first) {
                last++;
                if (!next.empty() && (next.front() == last)) {
                    next.pop();
                    ans--;
                }
                if (isprime[last]) {
                    ans++;
                    next.push(last * last);
                    for (int i = 2 * last; i < MAXN; i += last) isprime[i] = 0;
                }
            }
            rta[a[T].second] = ans;
        }
    }
    for (int i = 0; i < t; i++) cout << rta[i] << '\n';
    return 0;
}