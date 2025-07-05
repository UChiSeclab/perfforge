#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 0x3FFFFFFFFFFFFF;
struct entry {
    ll pos, full, part;
    bool operator<(const entry& o) const {
        if (full != o.full) return full > o.full;
        if (part != o.part) return part > o.part;
        return pos < o.pos;
    }
};

// Function declarations for the checker functions
void check_priority_queue_invariant(deque<vector<entry>>& pq, ll threshold);
void check_dense_islands_invariant(const vector<ll>& d, ll g);
void check_red_light_waiting_invariant(ll g, ll max_distance);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<ll> d(m);
    for (ll i = 0; i < m; i++) {
        cin >> d[i];
    }
    sort(begin(d), end(d));
    ll g, r;
    cin >> g >> r;

    // Check for dense safety islands
    check_dense_islands_invariant(d, g);

    vector<vector<ll>> res(m, vector<ll>(g, inf));
    res[0][0] = 0;
    ll offset = 0;
    deque<vector<entry>> pq;
    pq.push_back({{0, 0, 0}});

    ll max_distance = 0;
    for (size_t i = 1; i < d.size(); ++i) {
        max_distance = max(max_distance, abs(d[i] - d[i - 1]));
    }

    // Check if frequent red light waiting leads to slowdown
    check_red_light_waiting_invariant(g, max_distance);

    while (!pq.empty()) {
        offset++;
        auto tmp = pq.front();
        pq.pop_front();

        // Check the size of priority queue for potential performance bottleneck
        check_priority_queue_invariant(pq, 1000); // Example threshold

        for (auto e : tmp) {
            if (e.pos == m - 1) {
                if (e.part == 0) {
                    e.full--;
                    e.part += g;
                }
                cout << e.part + e.full * (r + g) << endl;
                return 0;
            }
            if (res[e.pos][e.part] != e.full) continue;
            for (ll px : {-1, 1}) {
                if (e.pos + px >= 0 && e.pos + px < m) {
                    entry next{e.pos + px, e.full,
                               e.part + abs(d[e.pos] - d[e.pos + px])};
                    if (next.part == g) {
                        next.part = 0;
                        next.full++;
                    }
                    if (next.part < g && res[next.pos][next.part] > next.full) {
                        res[next.pos][next.part] = next.full;
                        ll t = next.full * g + next.part - offset;
                        while (pq.size() <= t) pq.resize(t + 1);
                        pq[t].push_back(next);
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}

// Helper functions implementing the performance-characterizing invariants
void check_priority_queue_invariant(deque<vector<entry>>& pq, ll threshold) {
    if (pq.size() > threshold) {
        cerr << "Warning: Priority queue has grown large, indicating potential performance bottleneck!" << endl;
        abort();
    }
}

void check_dense_islands_invariant(const vector<ll>& d, ll g) {
    for (size_t i = 1; i < d.size(); ++i) {
        if (d[i] - d[i-1] < g) {
            cerr << "Warning: Dense safety islands detected within green light duration, indicating potential bottleneck!" << endl;
            abort();
        }
    }
}

void check_red_light_waiting_invariant(ll g, ll max_distance) {
    if (g < max_distance) {
        cerr << "Warning: Frequent red light waiting due to short green light duration!" << endl;
        abort();
    }
}