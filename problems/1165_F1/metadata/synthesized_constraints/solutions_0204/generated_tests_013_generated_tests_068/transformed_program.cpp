#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long int> k;
vector<pair<long long int, long long int>> deal;

// Checker functions
void check_day_iterations_invariant(long long day, long long sum) {
    if (day > 2 * sum) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive day iterations!" << endl;
        abort();
    }
}

void check_special_offers_invariant(const vector<long long>& reqd, long long cur) {
    long long unmet = 0;
    for (auto r : reqd) {
        unmet += r;
    }
    if (unmet > cur) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient use of special offers!" << endl;
        abort();
    }
}

void check_remaining_transactions_invariant(const vector<long long>& reqd) {
    long long total_unmet = 0;
    for (auto r : reqd) {
        total_unmet += r;
    }
    if (total_unmet > 500) { // Assuming half the total maximum sum as a rough threshold
        cerr << "Warning: Performance bottleneck condition triggered due to high number of remaining transactions!" << endl;
        abort();
    }
}

bool pred(long long day) {
    vector<long long int> last(n + 1, -1);
    for (long long int i = 1; i < m + 1; i++) {
        if (deal[i].first <= day) {
            last[deal[i].second] = max(last[deal[i].second], deal[i].first);
        }
    }
    vector<vector<long long int>> off(200005);
    for (long long int i = 1; i < n + 1; i++) {
        if (last[i] != -1) {
            off[last[i]].push_back(i);
        }
    }
    vector<long long int> reqd = k;
    long long cur = 0L;
    for (long long int i = 1; i < day + 1; i++) {
        cur++;
        for (auto j : off[i]) {
            if (cur >= reqd[j]) {
                cur -= reqd[j];
                reqd[j] = 0;
            } else {
                reqd[j] -= cur;
                cur = 0;
                break;
            }
        }
    }
    
    // Check special offers invariant
    check_special_offers_invariant(reqd, cur);
    
    long long sum = 0L;
    for (auto i : reqd) {
        sum += i;
    }
    
    // Check remaining transactions invariant
    check_remaining_transactions_invariant(reqd);
    
    return (sum * 2 <= cur);
}

int main() {
    cin >> n >> m;
    k.resize(n + 1);
    long long sum = 0L;
    for (long long int i = 1; i < n + 1; i++) {
        cin >> k[i];
        sum += k[i];
    }
    deal.resize(m + 1);
    for (long long int i = 1; i < m + 1; i++) {
        cin >> deal[i].first >> deal[i].second;
    }
    long long x = 0L;
    for (long long step = 2 * sum; step >= 1; step /= 2) {
        while (!pred(x + step)) x += step;
    }
    
    // Check day iterations invariant
    check_day_iterations_invariant(x + 1, sum);
    
    cout << x + 1;
    return 0;
}