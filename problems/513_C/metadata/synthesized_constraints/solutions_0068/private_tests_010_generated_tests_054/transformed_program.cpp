#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;

// Function prototypes for checks
void check_range_invariant(int l[], int r[], int n);
void check_overlap_invariant(int l[], int r[], int n);
void check_recursive_invariant(int n);

const int MX = 10100;
int vis[5][5][5], l[5], r[5], curnum, n;
double dp[5][5][5];

double func(int pos, int eNum, int bNum) {
    if (bNum > 1) return 0;
    if (pos == n) {
        if (eNum > 1 && !bNum) return 1;
        if (eNum && bNum) return 1;
        return 0;
    }
    if (vis[pos][eNum][bNum]) return dp[pos][eNum][bNum];
    vis[pos][eNum][bNum] = 0;
    double &ret = dp[pos][eNum][bNum];
    ret = 0;
    if (curnum >= l[pos] && curnum <= r[pos]) {
        double temp = (1.0 / (r[pos] - l[pos] + 1));
        temp *= func(pos + 1, eNum + 1, bNum);
        ret += temp;
    }
    if (r[pos] > curnum) {
        double temp = 1;
        if (l[pos] <= curnum) {
            temp *= (double)(r[pos] - curnum) / (double)(r[pos] - l[pos] + 1);
        }
        temp *= func(pos + 1, eNum, bNum + 1);
        ret += temp;
    }
    if (l[pos] < curnum) {
        double temp = 1;
        if (r[pos] >= curnum) {
            temp *= (double)(curnum - l[pos]) / (double)(r[pos] - l[pos] + 1);
        }
        temp *= func(pos + 1, eNum, bNum);
        ret += temp;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout.unsetf(ios::floatfield);
    cout.precision(10);
    cout.setf(ios::fixed, ios::floatfield);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    // Insert checks before processing
    check_range_invariant(l, r, n); // Check for large bid ranges
    check_overlap_invariant(l, r, n); // Check for overlapping bid ranges
    check_recursive_invariant(n); // Check for high branching factor

    double ans = 0;
    for (int i = 1; i < MX; ++i) {
        curnum = i;
        ans += i * func(0, 0, 0);
        memset(vis, 0, sizeof(vis));
    }

    cout << ans;
    return 0;
}

// Function definitions for checks
void check_range_invariant(int l[], int r[], int n) {
    for (int i = 0; i < n; ++i) {
        if ((r[i] - l[i]) > 5000) { // Arbitrary threshold for large range
            cerr << "Warning: Performance bottleneck condition triggered due to large bid range!" << endl;
            abort();
        }
    }
}

void check_overlap_invariant(int l[], int r[], int n) {
    int total_overlap = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (max(l[i], l[j]) <= min(r[i], r[j])) {
                total_overlap++;
            }
        }
    }
    if (total_overlap > 10) { // Arbitrary threshold for excessive overlap
        cerr << "Warning: Performance bottleneck condition triggered due to overlapping bid ranges!" << endl;
        abort();
    }
}

void check_recursive_invariant(int n) {
    if (n > 4) { // Since n can be at most 5, check if it's at the upper limit
        cerr << "Warning: Performance bottleneck condition triggered due to high branching factor!" << endl;
        abort();
    }
}