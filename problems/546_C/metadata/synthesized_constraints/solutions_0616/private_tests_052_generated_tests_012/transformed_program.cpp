#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to check repeated states to prevent infinite loops
void check_repeated_state_invariant(const set<pair<deque<ll>, deque<ll>>>& states, 
                                    const deque<ll>& s1, const deque<ll>& s2) {
    if (states.find({s1, s2}) != states.end()) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated card configuration detected!" << endl;
        abort();
    }
}

// Function to check for stalemate conditions
void check_stalemate_invariant(const deque<ll>& s1, const deque<ll>& s2) {
    if (s1.size() == s2.size()) {
        cerr << "Warning: Performance bottleneck condition triggered - potential stalemate due to balanced stacks!" << endl;
        abort();
    }
}

// Function to check for excessive number of rounds
void check_high_rounds_invariant(ll rounds, ll n) {
    if (rounds > 10 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive rounds without progress!" << endl;
        abort();
    }
}

void solve() {
    ll n;
    cin >> n;
    deque<ll> s1, s2;
    ll x, y;
    cin >> x;
    for (ll i = 0; i < x; i++) {
        cin >> y;
        s1.push_back(y);
    }
    cin >> x;
    for (ll i = 0; i < x; i++) {
        cin >> y;
        s2.push_back(y);
    }
    set<pair<deque<ll>, deque<ll>>> states;
    ll ans = 0;
    while (!s1.empty() && !s2.empty()) {
        ans++;
        check_high_rounds_invariant(ans, n); // Check for excessive rounds
        check_repeated_state_invariant(states, s1, s2); // Check for repeated states
        states.insert({s1, s2});

        x = s1.front();
        s1.pop_front();
        y = s2.front();
        s2.pop_front();
        if (x < y) {
            s2.push_back(x);
            s2.push_back(y);
        } else {
            s1.push_back(y);
            s1.push_back(x);
        }
    }

    cout << ans << " ";
    if (s1.empty()) {
        cout << "2";
    } else {
        cout << "1";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}