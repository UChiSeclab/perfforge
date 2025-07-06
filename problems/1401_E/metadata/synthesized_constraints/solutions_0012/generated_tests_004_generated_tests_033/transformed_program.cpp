#include <bits/stdc++.h>
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
using namespace std;

template <typename T>
struct BIT {
    vector<T> bit;
    int N;
    BIT(int n) : N(n) { bit.assign(++n, 0); }
    T sum(int i) {
        T s = 0;
        ++i;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, T x) {
        ++i;
        while (i < (int)bit.size()) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

// Checkers for performance bottlenecks
void check_vertical_segment_count(int m) {
    if (m > 10000) {  // Check if there are too many vertical segments
        cerr << "Warning: Performance bottleneck condition triggered - too many vertical segments!" << endl;
        abort();
    }
}

void check_overlapping_segments(const vector<ll>& ly, const vector<ll>& ry) {
    int overlapCount = 0;
    for (size_t i = 0; i < ly.size(); ++i) {
        for (size_t j = i + 1; j < ry.size(); ++j) {
            if (ly[j] <= ry[i] && ry[j] >= ly[i]) {
                overlapCount++;
                break;  // Only count each overlapping once
            }
        }
    }
    if (overlapCount > ly.size() / 2) {  // Check for substantial overlap
        cerr << "Warning: Performance bottleneck condition triggered - overlapping vertical segments!" << endl;
        abort();
    }
}

void check_frequent_bit_updates(int pos, int pos2, int m) {
    if (pos > m / 2 || pos2 > m / 2) {  // Simulate frequent updates if either position crosses half
        cerr << "Warning: Performance bottleneck condition triggered - frequent BIT updates!" << endl;
        abort();
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    check_vertical_segment_count(m);  // Check for too many vertical segments

    ll ans = 0;
    vector<ll> x(m);
    vector<ll> ly(m), ry(m);
    vector<pair<ll, pair<ll, ll>>> v;
    for (int i = 0; i < n; ++i) {
        ll y, lx, rx;
        cin >> y >> lx >> rx;
        v.emplace_back(y, make_pair(lx, rx));
        if (lx == 0 && rx == 1e6) ++ans;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> ly[i] >> ry[i];
        if (ly[i] == 0 && ry[i] == 1e6) ++ans;
    }

    check_overlapping_segments(ly, ry);  // Check for overlapping segments

    vector<pair<ll, ll>> add(m), sub(m);
    for (int i = 0; i < m; ++i) {
        add[i] = make_pair(ry[i], x[i]);
        sub[i] = make_pair(ly[i], x[i]);
    }
    sort(add.rbegin(), add.rend());
    sort(sub.rbegin(), sub.rend());
    sort(v.rbegin(), v.rend());
    int pos = 0, pos2 = 0, py = 0;
    BIT<ll> tree(1e6 + 1);
    for (int i = 1e6; i >= 0; --i) {
        while (pos < m && add[pos].first == i) {
            tree.add(add[pos].second, 1);
            ++pos;
        }
        if (py < n && v[py].first == i) {
            ans += tree.sum(v[py].second.second) - tree.sum(v[py].second.first - 1);
            ++py;
        }
        while (pos2 < m && sub[pos2].first == i) {
            tree.add(sub[pos2].second, -1);
            ++pos2;
        }
    }
    
    check_frequent_bit_updates(pos, pos2, m);  // Check for frequent BIT updates
    
    ans++;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}