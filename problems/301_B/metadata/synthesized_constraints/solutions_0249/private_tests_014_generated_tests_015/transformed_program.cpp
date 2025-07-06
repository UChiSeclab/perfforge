#include <bits/stdc++.h>
using namespace std;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}

long long INF = LLONG_MAX;
const long long M = 1000000007;
long long powm(long long, long long);
set<long long> s[105];
map<pair<int, int>, long long> mp;
map<long long, pair<int, int>> inv;
long long val[105];
long long d;
long long n;
long long a[105];

void check_dense_connectivity_invariant(int n, const map<long long, pair<int, int>>& inv) {
    int close_pairs = 0;
    int threshold = (n * (n - 1)) / 5;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int distance = abs(inv.at(i).first - inv.at(j).first) + abs(inv.at(i).second - inv.at(j).second);
            if (distance < 3) {
                close_pairs++;
            }
        }
    }
    if (close_pairs > threshold) {
        cerr << "Warning: Dense connectivity invariant triggered!" << endl;
        abort();
    }
}

void check_branching_factor_invariant(int n, long long d, const map<long long, pair<int, int>>& inv) {
    for (int i = 1; i <= n; ++i) {
        int reachable_count = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                long long distance = abs(inv.at(i).first - inv.at(j).first) + abs(inv.at(i).second - inv.at(j).second);
                if (distance * d <= 2 * d) {
                    reachable_count++;
                }
            }
        }
        if (reachable_count > n / 4) {
            cerr << "Warning: High branching factor invariant triggered!" << endl;
            abort();
        }
    }
}

void check_frequent_update_invariant(int n, const long long val[]) {
    int update_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (val[i] > 0) {
            update_count++;
        }
    }
    if (update_count > 3 * n / 4) {
        cerr << "Warning: Frequent updates invariant triggered!" << endl;
        abort();
    }
}

void check_queue_operations_invariant(int queue_op_count, int threshold) {
    if (queue_op_count > threshold) {
        cerr << "Warning: Extensive queue operations invariant triggered!" << endl;
        abort();
    }
}

bool dfs(int ind) {
    for (int i = 0; i < 105; i++) val[i] = -INF;
    for (int i = 0; i < 105; i++) s[i].clear();
    val[1] = ind;
    s[1].insert(1);
    queue<long long> q;
    q.push(1);
    int queue_op_count = 0; // Initialize the operation counter
    while (!q.empty()) {
        long long i = q.front();
        q.pop();
        for (int j = 1; j < n + 1; j++) {
            if (i == j) continue;
            long long dis = abs(inv[i].first - inv[j].first) + abs(inv[i].second - inv[j].second);
            dis *= d;
            if (val[i] >= dis) {
                long long stunned;
                if (s[i].find(j) == s[i].end()) {
                    stunned = a[j] - dis;
                } else
                    stunned = 0 - dis;
                if (val[j] <= val[i] + stunned) {
                    q.push(j);
                    queue_op_count++; // Track queue operations
                    val[j] = val[i] + stunned;
                    s[j].clear();
                    for (auto x : s[i]) s[j].insert(x);
                    s[j].insert(j);
                }
            }
        }
    }
    check_queue_operations_invariant(queue_op_count, 1000); // Set a threshold for operations
    return val[n] >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> d;
    for (int i = 2; i < n; i++) cin >> a[i];
    for (int i = 1; i < n + 1; i++) {
        long long x;
        cin >> x;
        long long y;
        cin >> y;
        mp[{x, y}] = i;
        inv[i] = {x, y};
    }
    a[1] = 0;
    a[n] = 0;
    for (int i = 0; i < 105; i++) val[i] = -INF;
    
    check_dense_connectivity_invariant(n, inv); // Check dense connectivity
    check_branching_factor_invariant(n, d, inv); // Check branching factor

    long long lo = 0, hi = 1e9;
    while (lo < hi) {
        long long mid = (lo + hi) >> 1;
        if (dfs(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo;
}

long long powm(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}