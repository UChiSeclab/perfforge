#include <bits/stdc++.h>
using namespace std;
const int maxn = 600005;
const long long mod = 998244353;
int n, m;
vector<int> k;
vector<pair<int, int>> offers;
long long sum_k;

// Check for high day count for sales offers
void check_high_days_count_invariant(int days_offers_count, int sum_k) {
    if (days_offers_count > 2 * sum_k) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive days with offers!" << endl;
        abort();
    }
}

// Check for sparse special offers
void check_sparse_offers_invariant(int m, int n) {
    if (m < n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse special offers!" << endl;
        abort();
    }
}

// Check for high transaction type requirements
void check_high_transaction_invariant(int max_k) {
    if (max_k > 800) { // Assuming a threshold close to the upper constraint of 1000
        cerr << "Warning: Performance bottleneck condition triggered - high transaction type requirement!" << endl;
        abort();
    }
}

// Check for binary search depth (indirectly based on sum_k)
void check_binary_search_depth(int left, int right) {
    if (right - left > 500) {  // Arbitrarily chosen threshold
        cerr << "Warning: Performance bottleneck condition triggered - excessive binary search depth!" << endl;
        abort();
    }
}

bool check(int i) {
    vector<int> offers_days(maxn + 5, 0);
    for (int j = 0; j < m; j++) {
        if (offers[j].first > i) continue;
        offers_days[offers[j].second] = offers[j].first;
    }
    vector<int> days_cnts(maxn + 5, 0);
    for (int j = 0; j < n; j++) {
        days_cnts[offers_days[j]] += k[j];
    }
    int balance = 0;
    int optimized = 0;
    for (int j = 1; j <= i; j++) {
        balance++;
        int delta = min(days_cnts[j], balance);
        balance -= delta;
        optimized += delta;
    }
    int left = sum_k - optimized;
    return left * 2 <= balance;
}

void solve() {
    cin >> n >> m;
    k.resize(n);
    sum_k = 0;
    int max_k = 0;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        sum_k += k[i];
        max_k = max(max_k, k[i]);
    }
    
    offers.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> offers[i].first >> offers[i].second;
        offers[i].second--;
    }
    sort(offers.begin(), offers.end());
    
    // Insert checks based on the derived invariants
    check_high_days_count_invariant(m, sum_k);
    check_sparse_offers_invariant(m, n);
    check_high_transaction_invariant(max_k);
    
    int sum = 0;
    int max_days = sum_k * 2;
    int l = 0;
    int r = max_days;
    
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
        
        check_binary_search_depth(l, r);
    }
    cout << r;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}