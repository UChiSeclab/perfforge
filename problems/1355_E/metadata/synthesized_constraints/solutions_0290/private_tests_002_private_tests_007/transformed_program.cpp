#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 998244353;
const int INF = 1e9 + 9;
const int MAXN = 1000006;
ll n, a, r, m, h[MAXN], t[MAXN];

// Function to check for large segments of identical heights
void check_identical_heights_invariant(const vector<ll>& t, ll n) {
    int identical_count = 0;
    for (ll i = 0; i < n - 1; ++i) {
        if (t[i] == t[i + 1]) {
            identical_count++;
        } else {
            if (identical_count > n / 2) {
                cerr << "Warning: Performance bottleneck condition triggered - large segment of identical heights!" << endl;
                abort();
            }
            identical_count = 0;
        }
    }
}

// Function to check if all operation costs are zero
void check_zero_cost_invariant(ll a, ll r, ll m) {
    if (a == 0 && r == 0 && m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - zero operation costs!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> r >> m;
    ll s1 = 0, s2 = 0;
    
    // Check for zero-cost invariant
    check_zero_cost_invariant(a, r, m);
    
    m = min(m, a + r);
    vector<ll> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        t[i] = h[i];
        s2 += h[i];
    }
    
    sort(t, t + n);
    
    // Check for identical heights invariant
    check_identical_heights_invariant(vector<ll>(t, t + n), n);
    
    ll ans = 1e18;
    for (ll i = 0; i < n; ++i) {
        while (t[i + 1] == t[i]) {
            s1 += t[i];
            s2 -= t[i];
            ++i;
        }
        s1 += t[i];
        s2 -= t[i];
        ll mean = (s1 + s2 + n - 1) / n;
        if (t[i] <= mean and t[i + 1] >= mean) {
            ans = min(ans, (s2 - mean * (n - i - 1)) * (m - a) + (mean * (i + 1) - s1) * a);
        }
        if (t[i] * (i + 1) - s1 >= s2 - t[i] * (n - i - 1)) {
            ans = min(ans, (s2 - t[i] * (n - i - 1)) * (m - a) + (t[i] * (i + 1) - s1) * a);
        }
    }
    swap(s1, s2);
    for (ll i = 0; i < n; ++i) {
        while (t[i + 1] == t[i]) {
            s1 += t[i];
            s2 -= t[i];
            ++i;
        }
        s1 += t[i];
        s2 -= t[i];
        ll mean = (s1 + s2) / n;
        if (t[i] <= mean and t[i + 1] >= mean) {
            ans = min(ans, (s2 - mean * (n - i - 1)) * r + (mean * (i + 1) - s1) * (m - r));
        }
        if (t[i] * (i + 1) - s1 <= s2 - t[i] * (n - i - 1)) {
            ans = min(ans, (s2 - t[i] * (n - i - 1)) * r + (t[i] * (i + 1) - s1) * (m - r));
        }
    }
    cout << ans << endl;
}