#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
long long sss[MAXN];

void check_days_budget_invariant(int n, int k, long long b, const vector<long long>& sss) {
    long long sum_of_cheap_squares = sss[0];
    if ((n - k > 50) && (sum_of_cheap_squares > b / 2)) {
        cerr << "Warning: Performance bottleneck - too many remaining days compared to budget!" << endl;
        abort();
    }
}

void check_cost_distribution_invariant(int n, const vector<int>& a) {
    int low_cost_squares = 0;
    for (int cost : a) {
        if (cost < 50) {
            low_cost_squares++;
        }
    }
    if (low_cost_squares > n / 2) {
        cerr << "Warning: Performance bottleneck - too many low-cost squares!" << endl;
        abort();
    }
}

void check_sequential_square_invariant(int n, int k, const vector<pair<int, int>>& buf) {
    int cheap_near_center = 0;
    for (int i = 0; i < k && i < buf.size(); ++i) {
        if (buf[i].first < 100) {
            cheap_near_center++;
        }
    }
    if (cheap_near_center > k / 2) {
        cerr << "Warning: Performance bottleneck - excessive sequential checking!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    long long b;
    cin >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<pair<int, int>> buf;
    for (int i = 0; i < n - 1; i++) buf.push_back(make_pair(a[i], i));
    sort(buf.begin(), buf.end());

    sss[n - 2] = buf[n - 2].first;
    for (int i = n - 3; i >= 0; i--) sss[i] = buf[i].first + sss[i + 1];

    // Invariant checks
    check_days_budget_invariant(n, k, b, sss);
    check_cost_distribution_invariant(n, a);
    check_sequential_square_invariant(n, k, buf);

    int fans = n - 1;
    for (int i = 0; i < n - 1; i++) {
        if (n - 2 - i >= k) {
            long long slaves = sss[n - 2 - (k - 1) + 1];
            if (slaves + buf[i].first > b) {
                fans = min(fans, buf[i].second);
            }
        } else {
            if (sss[n - 2 - k + 1] > b) fans = min(fans, buf[i].second);
        }
    }
    cout << fans + 1;
    return 0;
}