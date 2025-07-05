#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200623;

bool is_sqr(ll x) {
    ll sq = sqrt(x);
    return (sq * sq == x);
}

// Checker Function for Invariant #1
void check_square_distribution(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient square numbers initially!" << endl;
        abort();
    }
}

// Checker Function for Invariant #2
void check_non_square_processing(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive non-square processing!" << endl;
        abort();
    }
}

// Checker Function for Invariant #3
void check_distance_calculations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - costly distance calculations needed!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;
    ll a[N], sqr = 0, zero = 0;
    vector<ll> sqrv, other, dis;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (is_sqr(a[i])) {
            sqr++;
            if (!a[i]) zero++;
        } else
            other.push_back(a[i]);
    }

    // Place check for Invariant #1 after counting squares
    check_square_distribution(sqr < (n >> 1));

    if (sqr >= (n >> 1)) {
        ll non_zero_sqr = sqr - zero;
        ll val = sqr - (n >> 1);
        ll mn = min(non_zero_sqr, val);
        non_zero_sqr -= mn;
        val -= mn;
        cout << mn + (val << 1) << '\n';
        return 0;
    }
  
    for (int i = 0; i <= 31630; i++) {
        sqrv.push_back(i * i);
    }

    // Place check for Invariant #2 before processing non-square numbers
    check_non_square_processing(!other.empty());

    for (int i = 0; i < other.size(); i++) {
        ll lo = lower_bound(sqrv.begin(), sqrv.end(), other[i]) - sqrv.begin();
        ll mn = abs(sqrv[lo] - other[i]);
        if (lo) {
            mn = min(mn, abs(sqrv[lo - 1] - other[i]));
        }
        dis.push_back(mn);
    }

    sort(dis.begin(), dis.end());
    ll req = (n >> 1) - sqr;
    ll ans = 0;

    // Place check for Invariant #3 before calculating minimal moves
    check_distance_calculations(req > 0 && !dis.empty());

    for (int i = 0; i < req; i++) {
        ans += dis[i];
    }
    cout << ans << '\n';
}