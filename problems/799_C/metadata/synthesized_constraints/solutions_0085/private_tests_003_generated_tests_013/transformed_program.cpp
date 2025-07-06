#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
pair<pair<int, int>, pair<int, int> > mx1[N], mx2[N];
int cnt1[N], cnt2[N], p[N], b[N];
char ch[N];

void check_currency_range_invariant(int c, int d) {
    if (c > 90000 || d > 90000) {
        cerr << "Warning: Performance bottleneck condition triggered - large currency range!" << endl;
        abort();
    }
}

void check_sparse_updates_invariant(int updates_count, int threshold) {
    if (updates_count < threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse updates during iterations!" << endl;
        abort();
    }
}

void check_large_array_invariant(int array_size, int limit) {
    if (array_size > limit) {
        cerr << "Warning: Performance bottleneck condition triggered - large array overhead!" << endl;
        abort();
    }
}

int main() {
    int n, c, d;
    cin >> n >> c >> d;

    // Check for large iteration count over currency range
    check_currency_range_invariant(c, d);

    for (int i = 0; i < n; ++i) {
        cin >> b[i] >> p[i] >> ch[i];
        if (ch[i] == 'D') {
            mx1[p[i]].first.second = max(mx1[p[i]].first.second, b[i]);
        } else {
            mx2[p[i]].first.second = max(mx2[p[i]].first.second, b[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (ch[i] == 'D') {
            if (b[i] == mx1[p[i]].first.second) {
                cnt1[p[i]]++;
            }
        } else {
            if (b[i] == mx2[p[i]].first.second) {
                cnt2[p[i]]++;
            }
        }
    }

    int ind = -1, mx = 0, secondmx = 0, ind2 = -1;
    int update_count = 0;
    for (int i = 0; i <= d; i++) {
        if (mx1[i].first.second >= mx) {
            ind2 = ind;
            ind = i;
            secondmx = mx;
            mx = mx1[i].first.second;
            update_count++;
        } else if (mx1[i].first.second < mx && mx1[i].first.second > secondmx) {
            ind2 = i;
            secondmx = mx1[i].first.second;
            update_count++;
        }
        mx1[i].first.first = ind;
        mx1[i].second.first = ind2;
        mx1[i].first.second = mx;
        mx1[i].second.second = secondmx;
    }

    // Check for sparse updates during many iterations
    check_sparse_updates_invariant(update_count, 1000);  // Assuming a threshold of 1000 updates

    ind = -1, mx = 0, secondmx = 0, ind2 = -1;
    update_count = 0;
    for (int i = 0; i <= c; i++) {
        if (mx2[i].first.second >= mx) {
            ind2 = ind;
            ind = i;
            secondmx = mx;
            mx = mx2[i].first.second;
            update_count++;
        } else if (mx2[i].first.second < mx && mx2[i].first.second > secondmx) {
            ind2 = i;
            secondmx = mx2[i].first.second;
            update_count++;
        }
        mx2[i].first.first = ind;
        mx2[i].second.first = ind2;
        mx2[i].first.second = mx;
        mx2[i].second.second = secondmx;
    }

    // Check for sparse updates during many iterations
    check_sparse_updates_invariant(update_count, 1000);  // Assuming a threshold of 1000 updates

    // Check for high overhead from large arrays
    check_large_array_invariant(n, 90000);  // Assuming a limit of 90000 for array size

    int z = 0;
    for (int i = 0; i <= d; i++) {
        if (cnt1[i] > 1 && mx1[i].first.first == i) {
            z = max(z, mx1[i].first.second * 2);
        }
        if (!mx1[i].first.second) continue;
        if (mx2[c].first.second)
            z = max(z, mx1[i].first.second + mx2[c].first.second);
        if (!mx1[d - i].first.second) continue;
        if (mx1[d - i].first.first != mx1[i].first.first) {
            z = max(z, mx1[d - i].first.second + mx1[i].first.second);
        } else {
            if (mx1[d - i].second.second) {
                z = max(z, mx1[d - i].second.second + mx1[i].first.second);
            }
        }
    }
    for (int i = 0; i <= c; i++) {
        if (cnt2[i] > 1 && mx2[i].first.first == i) {
            z = max(z, mx2[i].first.second * 2);
        }
        if (!mx2[i].first.second) continue;
        if (mx1[d].first.second)
            z = max(z, mx2[i].first.second + mx1[d].first.second);
        if (!mx2[c - i].first.second) continue;
        if (mx2[c - i].first.first != mx2[i].first.first) {
            z = max(z, mx2[c - i].first.second + mx2[i].first.second);
        } else {
            if (mx2[c - i].second.second) {
                z = max(z, mx2[c - i].second.second + mx2[i].first.second);
            }
        }
    }
    cout << z << endl;
}