#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using dd = long double;

namespace {
static bool constexpr dbg = 0;
ll constexpr N = -1;
ll n, a, b;
string s;

void init() { 
    cin >> a >> b >> s; 
}

bool mv(ll &x, ll &y) {
    if (x == a && y == b) return true;
    for (auto ch : s) {
        if (ch == 'U')
            ++y;
        else if (ch == 'D')
            --y;
        else if (ch == 'L')
            --x;
        else
            ++x;
        if (x == a && y == b) return true;
    }
    return false;
}

// Check for performance bottlenecks: repetitive movements
void check_repetitive_movements(const string &s, long long a, long long b) {
    if (s.size() > 50 && abs(a) > 1e9 / 2 && abs(b) > 1e9 / 2) {
        cerr << "Warning: Performance bottleneck due to repetitive movements leading to excessive iterations!" << endl;
        abort();
    }
}

// Check for performance bottlenecks: inefficient progress
void check_inefficient_progress(long long dx, long long dy, long long a, long long b) {
    if ((dx == 0 || dy == 0) && (a != 0 || b != 0)) {
        cerr << "Warning: Performance bottleneck due to inefficient directional progress!" << endl;
        abort();
    }
}

// Check for performance bottlenecks: high loop execution
void check_high_loop_execution(long long a, long long b, long long dx, long long dy) {
    if ((abs(a) > 1e9 / 2 || abs(b) > 1e9 / 2) && (dx == 0 || dy == 0)) {
        cerr << "Warning: Performance bottleneck due to high loop execution without progress!" << endl;
        abort();
    }
}

void solve() {
    ll x = 0, y = 0;
    if (mv(x, y)) {
        cout << "Yes";
        return;
    }
    ll dx = x, dy = y;

    // Insert performance checks
    check_repetitive_movements(s, a, b);
    check_inefficient_progress(dx, dy, a, b);
    check_high_loop_execution(a, b, dx, dy);

    ll cnt = 0;
    if (dx)
        cnt = a / dx;
    else if (dy)
        cnt = b / dy;
    for (ll i = max(0LL, cnt - 200); i <= cnt + 200; ++i) {
        x = i * dx;
        y = i * dy;
        for (ll _ = 1; _ <= (ll)(200); ++_)
            if (mv(x, y)) {
                cout << "Yes";
                return;
            }
    }
    cout << "No";
    return;
}
}  // namespace

int main() {
    if (!dbg) {
        std::ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    cout << fixed << setprecision(20);
    init();
    solve();
    return 0;
}