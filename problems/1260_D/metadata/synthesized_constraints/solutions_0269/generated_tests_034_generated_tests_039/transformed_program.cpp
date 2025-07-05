#include <bits/stdc++.h>
using ll = long long;
const ll maxSize = 200007;
using namespace std;
ll a[maxSize];
unordered_map<ll, set<pair<ll, ll>>> dexToLR;

// Checker for trap density and overlap
void check_trap_density_invariant(const set<pair<ll, ll>>& traps) {
    if (traps.size() > 1000) { // Example threshold for high density
        cerr << "Warning: Performance bottleneck condition triggered - trap density too high!" << endl;
        abort();
    }
}

// Checker for low dexterity start
void check_dex_range_invariant(ll dex) {
    if (dex < maxSize / 10) { // Example threshold for low dex
        cerr << "Warning: Performance bottleneck condition triggered - dex too low, leading to inefficient scanning!" << endl;
        abort();
    }
}

// Checker for binary search convergence
void check_binary_search_invariant(int iterations) {
    if (iterations > 100) { // Example threshold for excessive iterations
        cerr << "Warning: Performance bottleneck condition triggered - binary search took too many iterations!" << endl;
        abort();
    }
}

ll minDisarmTime(const set<pair<ll, ll>>& traps) {
    ll time = 0;
    auto it = traps.begin();
    ll st = 0;
    ll end = -1;
    while (it != traps.end()) {
        auto next = *it;
        if (next.first > end) {
            time += end - st + 1;
            st = next.first;
            end = next.second;
        } else {
            end = max(end, next.second);
        }
        ++it;
    }
    time += end - st + 1;
    return 2 * time;
}

set<pair<ll, ll>> chooseTrapsByDex(ll dex) {
    check_dex_range_invariant(dex); // Check for low dexterity start
    set<pair<ll, ll>> result;
    for (ll i = dex; i < maxSize; ++i) {
        if (dexToLR.find(i) != dexToLR.end()) {
            auto& toInsert = dexToLR.at(i);
            result.insert(toInsert.begin(), toInsert.end());
        }
    }
    check_trap_density_invariant(result); // Check for trap density and overlap
    return result;
}

bool solve(ll dex, ll maxTime) {
    auto traps = chooseTrapsByDex(dex);
    auto time = minDisarmTime(traps);
    return time <= maxTime;
}

ll solve(ll maxTime) {
    ll minDex = 1;
    ll maxDex = maxSize;
    int iterations = 0; // Track binary search iterations
    while (minDex < maxDex) {
        ++iterations;
        ll mid = (minDex + maxDex) / 2 + 1;
        auto enoughTime = solve(mid, maxTime);
        if (enoughTime)
            maxDex = mid - 1;
        else
            minDex = mid;
    }
    check_binary_search_invariant(iterations); // Check binary search convergence
    auto enoughTime = solve(maxDex, maxTime);
    return (enoughTime ? maxDex : maxDex + 1);
}

int main() {
    ll n, m, k, t;
    cin >> m >> n >> k >> t;
    for (ll i = 0; i < m; ++i) cin >> a[i];
    for (ll i = 0; i < k; ++i) {
        ll l, d, r;
        cin >> l >> r >> d;
        dexToLR[d].emplace(l, r);
    }
    auto maxTime = t - n - 1;
    auto maxDexOfSoldier = solve(maxTime);
    ll answer = 0;
    for (ll i = 0; i < m; ++i)
        if (a[i] >= maxDexOfSoldier - 1) ++answer;
    cout << answer;
}