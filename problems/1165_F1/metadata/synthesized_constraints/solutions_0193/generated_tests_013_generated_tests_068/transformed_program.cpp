#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;

// Checker functions
void check_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count in outer loop!" << endl;
        abort();
    }
}

void check_special_offers_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient use of special offers!" << endl;
        abort();
    }
}

void check_transaction_set_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large required transaction set!" << endl;
        abort();
    }
}

void check_day_offer_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient day-to-offer mapping!" << endl;
        abort();
    }
}

int n, m;
const int MAX = 2010;
vector<int> vec;
vector<int> off[MAX];

bool isItPossible(int day) {
    int cur = 0;
    int req = accumulate(vec.begin(), vec.end(), 0);
    vector<int> temp = vec;
    vector<int> toff[MAX];
    vector<bool> vis(n + 1, false);

    for (int i = day; i >= 1; i--) {
        for (auto it : off[i]) {
            if (vis[it]) continue;
            vis[it] = true;
            toff[i].push_back(it);
        }
    }

    for (int i = 1; i <= day; i++) {
        cur++;
        if (req * 2 <= cur) {
            return true;
        }
        for (auto it : toff[i]) {
            int m = min(temp[it], cur);
            cur -= m;
            req -= m;
            temp[it] -= m;
        }
        if (req * 2 <= cur) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vec.push_back(0);
    int v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        vec.push_back(v);
    }
    int d, t;
    for (int i = 0; i < m; i++) {
        cin >> d >> t;
        off[d].push_back(t);
    }

    // Check the size of the transaction set
    int totalTransactions = accumulate(vec.begin(), vec.end(), 0);
    check_transaction_set_invariant(totalTransactions > 500); // Threshold chosen based on problem constraints

    int ans = 0;
    for (int i = 0; i <= 2000; i++) {
        if (i > 1500) {
            check_iteration_invariant(true); // Assuming a threshold beyond which iterations are considered too high
        }
        if (isItPossible(i)) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}