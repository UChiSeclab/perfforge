#include <bits/stdc++.h>
using namespace std;

typedef struct fountain {
    int b;
    int p;
    char type;
} fountain;

fountain f[100002];
vector<fountain> c_all, d_all;
int maxbc[100002] = {0};
int maxbd[100002] = {0};

int bin_search(vector<fountain>& a, int l, int r, int val) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (val < a[mid].p)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int sort(const void* x, const void* y) {
    if (((fountain*)x)->p == ((fountain*)y)->p)
        return ((fountain*)y)->b - ((fountain*)x)->b;
    return ((fountain*)x)->p - ((fountain*)y)->p;
}

// Check invariant 1 for large money limits
void check_money_limit_invariant(int c, int d) {
    if (c > 50000 || d > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large money limits!" << endl;
        abort();
    }
}

// Check invariant 2 for maximum cost reaching limits
void check_fountain_cost_invariant(int maxCoinCost, int maxDiamondCost, int c, int d) {
    if (maxCoinCost >= c || maxDiamondCost >= d) {
        cerr << "Warning: Performance bottleneck condition triggered due to maximum fountain cost reaching limits!" << endl;
        abort();
    }
}

// Check invariant 3 for excessive filtering
void check_fountain_filtering_invariant(int filteredCount, int n) {
    if (filteredCount > (n / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered due to many fountains passing the filter!" << endl;
        abort();
    }
}

int main() {
    int n, c, d, ans = 0, length, left_pos, left;
    cin >> n >> c >> d;
    
    // Insert check for money limits
    check_money_limit_invariant(c, d);
    
    for (int i = 1; i <= n; i++) cin >> f[i].b >> f[i].p >> f[i].type;
    qsort(f + 1, n, sizeof(fountain), sort);
    
    int maxCoinCost = 0, maxDiamondCost = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i].type == 'C' && f[i].p <= c) {
            c_all.push_back(f[i]);
            if (maxbc[f[i].p] < f[i].b) maxbc[f[i].p] = f[i].b;
            maxCoinCost = max(maxCoinCost, f[i].p);
        } else if (f[i].type == 'D' && f[i].p <= d) {
            d_all.push_back(f[i]);
            if (maxbd[f[i].p] < f[i].b) maxbd[f[i].p] = f[i].b;
            maxDiamondCost = max(maxDiamondCost, f[i].p);
        }
    }
    
    // Insert check for maximum cost reaching limits
    check_fountain_cost_invariant(maxCoinCost, maxDiamondCost, c, d);

    // Insert check for filtering performance
    check_fountain_filtering_invariant(c_all.size() + d_all.size(), n);

    for (int i = 1; i <= c; i++)
        if (maxbc[i] < maxbc[i - 1]) maxbc[i] = maxbc[i - 1];
    for (int i = 1; i <= d; i++)
        if (maxbd[i] < maxbd[i - 1]) maxbd[i] = maxbd[i - 1];
    if (maxbd[d] != 0 && maxbc[c] != 0) ans = maxbd[d] + maxbc[c];
    length = c_all.size();
    for (int i = length - 1; i > 0; i--) {
        left = c - c_all[i].p;
        left_pos = bin_search(c_all, 0, i - 1, left);
        if (left_pos) {
            ans = max(ans, c_all[i].b + maxbc[c_all[left_pos - 1].p]);
        }
    }
    length = d_all.size();
    for (int i = length - 1; i > 0; i--) {
        left = d - d_all[i].p;
        left_pos = bin_search(d_all, 0, i - 1, left);
        if (left_pos) ans = max(ans, d_all[i].b + maxbd[d_all[left_pos - 1].p]);
    }
    cout << ans << endl;
    return 0;
}