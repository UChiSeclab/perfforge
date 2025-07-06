#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;

// Checkers integrated from the performance invariants
void check_days_invariant(int n, int k) {
    if (n - k < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of days before the meeting!" << endl;
        abort();
    }
}

void check_fund_invariant(int n, int k) {
    if (n - k < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient days due to fund checking!" << endl;
        abort();
    }
}

void check_iteration_invariant(int n, int k) {
    if (k > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations over squares!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    long long b;
    cin >> b;
    
    // Integrate checks after reading inputs
    check_days_invariant(n, k);
    check_fund_invariant(n, k);
    check_iteration_invariant(n, k);

    vector<pair<int, int>> ar(n - 1);
    for (int i = 0; i < (n - 1); ++i) {
        cin >> ar[i].first;
        ar[i].second = i + 1;
    }
    sort((ar).begin(), (ar).end());
    reverse((ar).begin(), (ar).end());
    
    long long s = 0;
    int mn = n;
    for (int i = 0; i < (k - 1); ++i) {
        s += ar[i].first;
        mn = min(mn, ar[i].second);
    }
    
    int res = n;
    if (b < s + ar[k - 1].first) res = mn;
    for (int i = k - 1; i < n - 1; ++i) {
        if (b < s + ar[i].first) res = min(res, ar[i].second);
    }
    cout << res;
    return 0;
}