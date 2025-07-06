#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int last[MAXN], k[MAXN];
pair<int, int> offer[MAXN + 1];
int n, m, sum;

// Checker functions
void check_offer_scheduling(int m, int d_max) {
    if (m > 500 && d_max > 500) { // arbitrary thresholds for complex offer scheduling
        cerr << "Warning: Performance bottleneck condition triggered due to complex offer scheduling!" << endl;
        abort();
    }
}

void check_microtransaction_requirement(int total_k, int m) {
    if (total_k > 700 && m < 10) { // condition for misalignment of offers and needs
        cerr << "Warning: Performance bottleneck condition triggered due to misalignment of offers and needs!" << endl;
        abort();
    }
}

void check_recursion_depth(int hi, int lo) {
    if (hi - lo > 800) { // if binary search range is too large
        cerr << "Warning: Performance bottleneck condition triggered due to extensive recursion depth!" << endl;
        abort();
    }
}

bool isOK(int d) {
    int money = 0, cur = 0, hi = min(MAXN, d);
    memset(last, 0, sizeof(int) * n);
    for (int i = 0; offer[i].first <= hi; ++i)
        last[offer[i].second] = offer[i].first;
    vector<vector<int>> day(MAXN + 1);
    for (int i = 0; i < n; ++i)
        if (last[i]) day[last[i]].push_back(i);
    for (int i = 1; i <= hi; ++i) {
        ++money;
        for (auto x : day[i]) money -= min(k[x], money);
    }
    return 2 * sum + money - hi <= d;
}

int solve() {
    int lo = sum, hi = sum * 2, x = 0;

    // Check recursion depth before binary search
    check_recursion_depth(hi, lo);

    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (isOK(mid))
            x = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    return x;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(last, 0, sizeof(int) * m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", k + i);
        sum += k[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        offer[i] = pair<int, int>{x, y - 1};
    }
    sort(offer, offer + m);
    offer[m].first = MAXN * 4;
    
    // Check offer scheduling before solving
    check_offer_scheduling(m, offer[m - 1].first);

    // Check microtransaction requirements
    check_microtransaction_requirement(sum, m);

    cout << solve() << endl;
    return 0;
}