#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

// Checkers for performance bottlenecks
void check_rabbits_carrots_invariant(long long n, long long k) {
    if (k > 10 * n) {  // Example threshold
        cerr << "Warning: Potential performance bottleneck - number of rabbits significantly exceeds number of carrots!" << endl;
        abort();
    }
}

void check_large_carrots_invariant(const vector<long long>& carrots) {
    for (auto length : carrots) {
        if (length > 100000) {  // Example threshold
            cerr << "Warning: Performance bottleneck - large carrot sizes requiring multiple splits!" << endl;
            abort();
        }
    }
}

void check_priority_queue_invariant(long long k, long long n) {
    if (k - n > 10000) {  // Example threshold
        cerr << "Warning: Performance bottleneck - excessive priority queue operations due to large k - n!" << endl;
        abort();
    }
}

inline long long calc(long long l, long long p) {
    long long b = l / p, t = l % p;
    return b * b * (p - t) + (b + 1) * (b + 1) * t;
}

struct cmp {
    bool operator()(const pair<long long, long long> &a,
                    const pair<long long, long long> &b) {
        return calc(a.first, a.second) - calc(a.first, a.second + 1) <
               calc(b.first, b.second) - calc(b.first, b.second + 1);
    }
};

void solve() {
    long long n, k;
    cin >> n >> k;

    // Insert checker for the number of rabbits relative to carrots
    check_rabbits_carrots_invariant(n, k);

    vector<long long> v(n);
    cin >> v;

    // Insert checker for large carrots requiring multiple splits
    check_large_carrots_invariant(v);

    // Insert checker for excessive priority queue operations
    check_priority_queue_invariant(k, n);

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
    for (auto x : v) pq.push({x, 1});
    for (int i = 0; i < k - n; i++) {
        auto tp = pq.top();
        pq.pop();
        pq.push({tp.first, tp.second + 1});
    }

    long long ans = 0;
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        ans += calc(tp.first, tp.second);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long T = 1;
    while (T--) {
        solve();
    }
    return 0;
}